#ifndef NODEDBL_H
#define NODEDBL_H

#include <node.h>


class nodeDbl : public node
{
    public:
        /** Default constructor */
        nodeDbl();
        /** Default destructor */
        virtual ~nodeDbl();

        /** Access nodeData
         * \return The current value of nodeData
         */
        void* GetnodeDataPtr() { return nodeDataPtr; }
        /** Set nodeData
         * \param val New value to set
         */
        /** Access nodeData as vector<int> data
         * \return The current value of nodeData
         */
        vector<double> GetnodeData() { return vnodeData; }

        /** Set nodeData
         * \param val New value to set
         */
        void SetnodeData(void* val) {
            nodeDataPtr = val;
            vector<double>* nodeData;
            nodeData = static_cast<vector<double>* >( nodeDataPtr);
            vnodeData = *nodeData;
        }

        vector<double> getDataRange(int start, int ending);

        void serialize();
        void display();
        string getNodeJSON();
        string tostring();

    protected:

    private:
        void* nodeDataPtr;//!< Member variable "nodeData"//!< Member variable "nodeData"
        vector<double> vnodeData;
};

#endif // NODEDBL_H
