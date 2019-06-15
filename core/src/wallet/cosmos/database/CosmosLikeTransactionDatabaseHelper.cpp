/*
 *
 * RIppleLikeTransactionDatabaseHelper
 *
 * Created by El Khalil Bellakrid on 06/01/2019.
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


#include "CosmosLikeTransactionDatabaseHelper.h"
#include <database/soci-option.h>
#include <database/soci-date.h>
#include <database/soci-number.h>
#include <crypto/SHA256.hpp>
#include <wallet/common/database/BlockDatabaseHelper.h>

using namespace soci;

namespace ledger {
    namespace core {

        bool CosmosLikeTransactionDatabaseHelper::getTransactionByHash(soci::session &sql,
                                                                       const std::string &hash,
                                                                       CosmosLikeBlockchainExplorerTransaction &tx) {

            //TODO
            /*
            rowset<row> rows = (sql.prepare << "SELECT  tx.hash, tx.value, tx.time, "
                    " tx.sender, tx.receiver, tx.fees, tx.confirmations, "
                    "block.height, block.hash, block.time, block.currency_name "
                    "memo.data, memo.fmt, memo.ty "
                    "FROM cosmos_transactions AS tx "
                    "LEFT JOIN blocks AS block ON tx.block_uid = block.uid "
                    "LEFT JOIN cosmos_memos AS memo ON memo.transaction_uid = tx.transaction_uid "
                    "WHERE tx.hash = :hash"
                    "ORDER BY memo.array_index ASC", use(hash));

            for (auto &row : rows) {
                inflateTransaction(sql, row, tx);
                return true;
            }
            */
            return false;
        }

        bool CosmosLikeTransactionDatabaseHelper::inflateTransaction(soci::session &sql,
                                                                     const soci::row &row,
                                                                     CosmosLikeBlockchainExplorerTransaction &tx) {
            tx.hash = row.get<std::string>(0);
            tx.value = BigInt::fromHex(row.get<std::string>(1));
            tx.receivedAt = row.get<std::chrono::system_clock::time_point>(2);
            tx.sender = row.get<std::string>(3);
            tx.receiver = row.get<std::string>(4);
            //TODO: gas limit and price
            tx.confirmations = get_number<uint64_t>(row, 6);
            if (row.get_indicator(7) != i_null) {
                CosmosLikeBlockchainExplorer::Block block;
                block.height = get_number<uint64_t>(row, 7);
                block.hash = row.get<std::string>(8);
                block.time = row.get<std::chrono::system_clock::time_point>(9);
                block.currencyName = row.get<std::string>(10);
                tx.block = block;
            }


            return true;
        }

        bool CosmosLikeTransactionDatabaseHelper::transactionExists(soci::session &sql,
                                                                    const std::string &cosmosTxUid) {
            int32_t count = 0;
            sql << "SELECT COUNT(*) FROM cosmos_transactions WHERE transaction_uid = :cosmosTxUid", use(cosmosTxUid), into(
                    count);
            return count == 1;
        }

        std::string CosmosLikeTransactionDatabaseHelper::createCosmosTransactionUid(const std::string &accountUid,
                                                                                    const std::string &txHash) {
            auto result = SHA256::stringToHexHash(fmt::format("uid:{}+{}", accountUid, txHash));
            return result;
        }

        std::string CosmosLikeTransactionDatabaseHelper::putTransaction(soci::session &sql,
                                                                        const std::string &accountUid,
                                                                        const CosmosLikeBlockchainExplorerTransaction &tx) {
            auto blockUid = tx.block.map<std::string>([](const CosmosLikeBlockchainExplorer::Block &block) {
                return block.getUid();
            });

            auto cosmosTxUid = createCosmosTransactionUid(accountUid, tx.hash);

            if (transactionExists(sql, cosmosTxUid)) {
                // UPDATE (we only update block information)
                if (tx.block.nonEmpty()) {
                    sql << "UPDATE cosmos_transactions SET block_uid = :uid WHERE hash = :tx_hash",
                            use(blockUid), use(tx.hash);
                }
                return cosmosTxUid;
            } else {
                // Insert
                if (tx.block.nonEmpty()) {
                    BlockDatabaseHelper::putBlock(sql, tx.block.getValue());
                }
                auto hexValue = tx.value.toHexString();
                /*
                sql
                        << "INSERT INTO cosmos_transactions VALUES(:tx_uid, :hash, :value, :block_uid, :time, :sender, :receiver, :fees, :confirmations)",
                        use(cosmosTxUid),
                        use(tx.hash),
                        use(hexValue),
                        use(blockUid),
                        use(tx.receivedAt),
                        use(tx.sender),
                        use(tx.receiver),
                        use(hexFees),
                        use(tx.confirmations);
                */
                return cosmosTxUid;
            }
        }
    }
}