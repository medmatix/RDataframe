#include "dataframe.h"

dataframe::dataframe()
{
    //ctor
}

dataframe::~dataframe()
{
    //dtor
}

/**class utility methods */
    /** add a new data variable column (node) to end position*/
    //void addDataNode(int posNum, node dNode){}
    /** remove node completely at posNum*/
    void removeDataNode(int posNum){}
    /** swap positions of two nodes in the frame data vector */
    void swapDataNodes(int firstPos, int secondPos){}
    /**inserts from pos node at to position, and moves rest one to right*/
    void moveDataNode(int fromPos, int toPos){}
    /** load data from a test file into the dataNodes*/
    void loadDataFromFile(string fileName, bool hasHeader, int startRead, int endRead, string sepChars){}
    /** save data and column names into a text file*/
    void saveDataFromFile(string fileName, bool hasHeader, string sepChars, bool append){}
    /** select a subset of variable/nodes data and stor in a new dataframe*/
    vector<node> subSetDataframe(vector<int> nodeSet){}
    /** serialize the dataframe object*/
    void serialize(){}
    /** display the dataframe object, meta-data and variables data*/
    void display(){}
    /** convert all information (metadat and variable data into a linear string*/
    string toString(){}
