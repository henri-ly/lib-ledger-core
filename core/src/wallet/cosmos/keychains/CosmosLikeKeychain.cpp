/*
 *
 * CosmosLikeKeychain
 *
 * Created by El Khalil Bellakrid on 14/06/2019.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ledger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */


#include "CosmosLikeKeychain.h"
#include <api/Currency.hpp>
#include <crypto/HASH160.hpp>
#include <cosmos/bech32/CosmosBech32.h>

namespace ledger {
    namespace core {
		static HashAlgorithm COSMOS_HASH_ALGO("atom");

		CosmosLikeKeychain::CosmosLikeKeychain(const std::vector<uint8_t>& pubbKey,
											   const DerivationPath& path,
											   const api::Currency& currency) {
			_pubKey = pubbKey;
			_address = std::make_shared<CosmosLikeAddress>(currency, HASH160::hash(pubbKey, COSMOS_HASH_ALGO),
														   std::vector<uint8_t>(), api::CosmosBech32Type::ADDRESS, optional<std::string>(path.toString()));
		}

		CosmosLikeKeychain::Address CosmosLikeKeychain::getAddress() const {
			return _address;
		}

		bool CosmosLikeKeychain::contains(const std::string &address) const {
			return _address->toBech32() == address || _address->toString() == address;
		}

		std::string CosmosLikeKeychain::getRestoreKey() const {
			return CosmosBech32(api::CosmosBech32Type::PUBLIC_KEY).encode(_pubKey, {});
		}

		const std::vector<uint8_t>& CosmosLikeKeychain::getPublicKey() const {
			return _pubKey;
		}

		std::shared_ptr<CosmosLikeKeychain>
		CosmosLikeKeychain::restore(const DerivationPath &path,
									const api::Currency &currency,
									const std::string &restoreKey) {
			auto p = CosmosBech32(api::CosmosBech32Type::PUBLIC_KEY).decode(restoreKey);
			return std::make_shared<CosmosLikeKeychain>(std::get<1>(p), path, currency);
		}
	}
}
