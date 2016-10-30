#ifndef NODESTR_H
#define NODESTR_H

#include <node.h>


class nodeStr : public node
{
    public:
        /** Default constructor */
        nodeStr();
        /** Default destructor */
        virtual ~nodeStr();

        /** Access nodeData
         * \return The current value of nodeData
         */
        void* GetnodeDataPtr() { return nodeDataPtr; }


        /** Access nodeData as vector<int> data
         * \return The current value of nodeData
         */
        vector<string> GetnodeData() { return vnodeData; }

        /** Set nodeData
         * \param val New value to set
         */
        void SetnodeData(void* val) {
            nodeDataPtr = val;
            vector<string>* nodeData;
            nodeData = static_cast<vector<string>* >( nodeDataPtr);
            vnodeData = *nodeData;
        }

        vector<string> getDataRange(int start, int ending);

        void serialize();
        void display();
        string getNodeJSON();
        string tostring();


    protected:

    private:

        void* nodeDataPtr;//!< Member variable "nodeData"
        vector<string> vnodeData;
};

#endif // NODESTR_H
