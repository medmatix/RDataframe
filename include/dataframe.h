#ifndef DATAFRAME_H
#define DATAFRAME_H

//#include "category.h"
#include "node.h"
#include "nodeInt.h"
#include "nodeDbl.h"
#include "nodeStr.h"
#include "nodeCat.h"

using namespace std;

class dataframe
{
    public:
        /** Default constructor */
        dataframe();
        /** Default destructor */
        virtual ~dataframe();

        /** Access frameName
         * \return The current value of frameName
         */
        string GetframeName() { return frameName; }
        /** Set frameName
         * \param val New value to set
         */
        void SetframeName(string val) { frameName = val; }
        /** Access numVars
         * \return The current value of numVars
         */
        int GetnumVars() { return numVars; }
        /** Set numVars
         * \param val New value to set
         */
        void SetnumVars(int val) { numVars = val; }
        /** Access numRows
         * \return The current value of numRows
         */
        int GetnumRows() { return numRows; }
        /** Set numRows
         * \param val New value to set
         */
        void SetnumRows(int val) { numRows = val; }
        /** Access dataNodes
         * \return The current value of dataNodes
         */
        vector<node> GetdataNodes() { return dataNodes; }
        /** Set dataNodes
         * \param val New value to set
         */
        void SetdataNodes(vector<node> val) { dataNodes = val; }
        /** add a new data variable column (node) to end position*/
        void addDataNode(int posNum, node dNode);
        /** remove node completely at posNum*/
        void removeDataNode(int posNum);
        /** swap positions of two nodes in the frame data vector */
        void swapDataNodes(int firstPos, int secondPos);
        /**inserts from pos node at to position, and moves rest one to right*/
        void moveDataNode(int fromPos, int toPos);
        /** load data from a test file into the dataNodes*/
        void loadDataFromFile(string fileName, bool hasHeader, int startRead, int endRead, string sepChars);
        /** save data and column names into a text file*/
        void saveDataFromFile(string fileName, bool hasHeader, string sepChars, bool append);
        /** select a subset of variable/nodes data and stor in a new dataframe*/
        vector<node> subSetDataframe(vector<int> nodeSet);
        /** serialize the dataframe object*/
        void serialize();
        /** display the dataframe object, meta-data and variables data*/
        void display();
        /** convert all information (metadat and variable data into a linear string*/
        string toString();




    protected:

    private:
        string frameName; //!< name of data table (data.frame)
        int numVars; //!< number of data variables ( contained in node objects) in the tables
        int numRows; //!< number of rows in the table ie. the length of the data vectors in the nodes.
        vector<node> dataNodes; //!< a vector of nodes each representing a variable and it's data
};

#endif // DATAFRAME_H
