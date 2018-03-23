// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from bitcoin_like_wallet.djinni

package co.ledger.core;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class BitcoinLikeTransactionBuilder {
    public abstract BitcoinLikeTransactionBuilder addInput(String transactionHash, int index, int sequence);

    public abstract BitcoinLikeTransactionBuilder addOutput(Amount amount, BitcoinLikeScript script);

    public abstract void addChangePath(String path);

    public abstract BitcoinLikeTransactionBuilder setNumberOfChangeAddresses(int count);

    public abstract BitcoinLikeTransactionBuilder pickInputs(BitcoinLikePickingStrategy strategy, int sequence);

    public abstract BitcoinLikeTransactionBuilder sendToAddress(Amount amount, String address);

    public abstract BitcoinLikeTransactionBuilder setFeesPerByte(Amount fees);

    public abstract void build(BitcoinLikeTransactionCallback callback);

    private static final class CppProxy extends BitcoinLikeTransactionBuilder
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            destroy();
            super.finalize();
        }

        @Override
        public BitcoinLikeTransactionBuilder addInput(String transactionHash, int index, int sequence)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_addInput(this.nativeRef, transactionHash, index, sequence);
        }
        private native BitcoinLikeTransactionBuilder native_addInput(long _nativeRef, String transactionHash, int index, int sequence);

        @Override
        public BitcoinLikeTransactionBuilder addOutput(Amount amount, BitcoinLikeScript script)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_addOutput(this.nativeRef, amount, script);
        }
        private native BitcoinLikeTransactionBuilder native_addOutput(long _nativeRef, Amount amount, BitcoinLikeScript script);

        @Override
        public void addChangePath(String path)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_addChangePath(this.nativeRef, path);
        }
        private native void native_addChangePath(long _nativeRef, String path);

        @Override
        public BitcoinLikeTransactionBuilder setNumberOfChangeAddresses(int count)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_setNumberOfChangeAddresses(this.nativeRef, count);
        }
        private native BitcoinLikeTransactionBuilder native_setNumberOfChangeAddresses(long _nativeRef, int count);

        @Override
        public BitcoinLikeTransactionBuilder pickInputs(BitcoinLikePickingStrategy strategy, int sequence)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_pickInputs(this.nativeRef, strategy, sequence);
        }
        private native BitcoinLikeTransactionBuilder native_pickInputs(long _nativeRef, BitcoinLikePickingStrategy strategy, int sequence);

        @Override
        public BitcoinLikeTransactionBuilder sendToAddress(Amount amount, String address)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_sendToAddress(this.nativeRef, amount, address);
        }
        private native BitcoinLikeTransactionBuilder native_sendToAddress(long _nativeRef, Amount amount, String address);

        @Override
        public BitcoinLikeTransactionBuilder setFeesPerByte(Amount fees)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_setFeesPerByte(this.nativeRef, fees);
        }
        private native BitcoinLikeTransactionBuilder native_setFeesPerByte(long _nativeRef, Amount fees);

        @Override
        public void build(BitcoinLikeTransactionCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_build(this.nativeRef, callback);
        }
        private native void native_build(long _nativeRef, BitcoinLikeTransactionCallback callback);
    }
}
