#ifndef NODEINT_H
#define NODEINT_H

#include <node.h>


class nodeInt : public node
{
    public:
        /** Default constructor */
        nodeInt();
        /** Default destructor */
        virtual ~nodeInt();
        /** meta-data only constructor */
        nodeInt(string nId, int nPosNumb,string nName, string nType, int nElems);
        /** all-data constructor */
        nodeInt(string nId, int nPosNumb,string nName, string nType, int nElems, void* nPrev, void* nNext, void* nData);


        /** Access nodeData
         * as vector
         * \return The current value of nodeData
         */
        void* GetnodeDataPtr() { return nodeDataPtr; }

        /** Access nodeData as vector<int> data
         * \return The current value of nodeData
         */
        vector<int> GetnodeData() { return vnodeData; }

        /** Set nodeData
         * \param val New value to set
         */
        void SetnodeData(void* val) {
            nodeDataPtr = val;
            vector<int>* nodeData;
            nodeData = static_cast<vector<int>* >( nodeDataPtr);
            vnodeData = *nodeData;
        }

        vector<int> getDataRange(int start, int ending);

        void serialize();
        void display();
        string getNodeJSON();
        string tostring();

    protected:

    private:
        void* nodeDataPtr;//!< Member variable "nodeData"
        vector<int> vnodeData;
};

#endif // NODEINT_H
