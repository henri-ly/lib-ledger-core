/*
 *
 * CosmosBech32
 *
 * Created by El Khalil Bellakrid on 15/06/2019.
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

#include "CosmosBech32.h"

namespace ledger {
    namespace core {
        CosmosBech32::CosmosBech32(api::CosmosBech32Type type) : BTCBech32("btc", 0) {
            switch (type) {
                case api::CosmosBech32Type::PUBLIC_KEY :
                    _bech32Params = COSMOS_PUB;
                    break;
                case api::CosmosBech32Type::PUBLIC_KEY_VAL :
                    _bech32Params = COSMOS_PUB_VAL;
                    break;
                case api::CosmosBech32Type::ADDRESS :
                    _bech32Params = COSMOS;
                    break;
                case api::CosmosBech32Type::ADDRESS_VAL :
                    _bech32Params = COSMOS_VAL;
                    break;
            }
        }
    }
}

