/*
 *
 * CosmosLikeAccount
 *
 * Created by Alexis Le Provost on 06/11/2019.
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

#pragma once

namespace ledger {
    namespace core {
        namespace constants {
			// use raw char array here to be compliant with rapidjson
			constexpr const char kMsgSend[] = "cosmos-sdk/MsgSend";
			constexpr const char kMsgDelegate[] = "cosmos-sdk/MsgDelegate";
			constexpr const char kMsgUndelegate[] = "cosmos-sdk/MsgUndelegate";
			constexpr const char kMsgRedelegate[] = "cosmos-sdk/MsgBeginRedelegate";
			constexpr const char kMsgSubmitProposal[] = "cosmos-sdk/MsgSubmitProposal";
			constexpr const char kMsgVote[] = "cosmos-sdk/MsgVote";
			constexpr const char kMsgDeposit[] = "cosmos-sdk/MsgDeposit";
			constexpr const char kMsgWithdrawDelegationReward[] = "cosmos-sdk/MsgWithdrawDelegationReward";
			
			constexpr const char kType[] = "type";
			constexpr const char kValue[] = "value";
			constexpr const char kFromAddress[] = "from_address";
			constexpr const char kToAddress[] = "to_address";
			constexpr const char kAmount[] = "amount";
			constexpr const char kDenom[] = "denom";
			constexpr const char kDelegatorAddress[] = "delegator_address";
			constexpr const char kValidatorAddress[] = "validator_address";
			constexpr const char kValidatorSrcAddress[] = "validator_src_address";
			constexpr const char kValidatorDstAddress[] = "validator_dst_address";
			constexpr const char kContent[] = "content";
			constexpr const char kTitle[] = "title";
			constexpr const char kDescription[] = "description";
			constexpr const char kProposer[] = "proposer";
			constexpr const char kInitialDeposit[] = "initial_deposit";
			constexpr const char kVoter[] = "voter";
			constexpr const char kProposalId[] = "proposal_id";
			constexpr const char kOption[] = "option";
			constexpr const char kDepositor[] = "depositor";
            constexpr const char kFee[] = "fee";
            constexpr const char kMessages[] = "msgs";
            constexpr const char kGas[] = "gas";
            constexpr const char kMemo[] = "memo";
            constexpr const char kSequence[] = "sequence";
            constexpr const char kAccountNumber[] = "account_number";
            constexpr const char kChainId[] = "chain_id";
			constexpr const char kPubKey[] = "pub_key";
			constexpr const char kSignature[] = "signature";
        }
    }
}