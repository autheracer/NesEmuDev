
//header for MemByte class
class MemByte{
    public:
        MemByte();
        int  read();           //return data for this MemByte
        void write(int dataIn); //set data for this MemByte

    private:
        int data;           //data for this MemByte
};
