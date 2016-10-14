/** \file
 *\page
 * Source Files:
 *
 * *Dataframe.cpp*
 *
 * (see also Node.cpp *csvToStrArray.cpp*, *Category.cpp* and *main.cpp*.)
 *
 * ##An R-type dataframe data-structure class for C++
 *
 * @author David York
 * @date Saturday August 13, 2016
 * @version 0.8
 *
 * @brief This creates a datatype "dataframe" modeled on the R language datatype.
 * Initial memory order is simulated or forced column major.
 *
 *  The Dataframe class is an R-like data structure serving as a container for a
 *  dataset to be used in data analysis procedures.
 *
 *  It consists of fields in support of a set of variables contained in Node
 *  structures as a vector<Node>.
 *  The Node class is defined as an external dependency of the dataframe. It
 *  should be thought of as a table like structure with the columns containing
 *  the variable "Nodes" and the rows containing the observation sets of
 *  related variables.
 *
 *  Class methods maintain and manipulate the dataframe and it's observations
 *  and variable.
 *
 *
 * &copy; 2016 David York
 */
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <typeinfo>
#include <cxxabi.h>
#include <array>
#include <initializer_list>
#include <boost/any.hpp>

#include "node.hpp"
#include "dataframe.hpp"
#include "csvLoad.hpp"

using namespace std;


    dataframe::dataframe() {}

    /** . . . a constructor with the first variable/Node initializes rows and columns to (0,0)*/
    dataframe::dataframe(node varNode) {
        ncols = 0;
        nrows = 0;
        colNames.push_back(varNode.getVarName());
        varsGrp = varNode;
    }

    /** . . . constructor with dataframe name, number of rows and number of columns in table */
    dataframe::dataframe(string s, int r, int c) {
        dfName = s;
        nrows = r;
        ncols = c;
    }

    /** Dataframe class methods
     *  helper methods (internal/protected)
     *  converters public may be used internally and externally
     *  getters - public
     *  setters - public
     *  utility methods public (usually used externally)
     *  displayers - public
     */

    /** create a vector of variable (column) types as response to query of dataframe
     *
     *
     */
     vector<string> dataframe::createTypesVector() {
         vector<string> varTypes;
         //Reads the type of each node
         //constructs a vector<string> from the types of the nodes in the dataframe
         //returns the vector list
         return varTypes;
     }
    /** create a table of observations from the dataframe listing variable
     *  observation(s) (values) as tuples,
     *  @param none
     *  @return none (void)
     */
    void dataframe::createObsDataframe() {
    }

    /** create a tuple from a specific row of variables elements, an internal
     *  helper function for the dataframe
     * @param nrow  the row to read accross the table
     * @return obsRow a tuple (pointer to) with the data by type from the line
     */
     boost::any dataframe::createObsTuple() {
       auto obs = make_tuple("string", 0);
       return  obs;
    }

    /** get the whole dataframe as a vector of nodes
     *  @param none
     *  @return dataframe, ie. a vector of nodes which is the dataframe itself
     */
    vector<node> dataframe::getDataframe() {
        return df;
    }

    /** get the dataframe name,
     *  @param none
     *  @return a string with the dataframe's name
     */
    string dataframe::getDataFrameName() {
        return dfName;
    }

    /** get observations from a row of the dataframe structure
         *  observation(s) as tuples,
         *  @param the row to fetch
         *  @return pointer to tuple containing variable values in the row
         *
         */
    void* dataframe::getObs(int rowNumber) {                                             // INCOMPLETE function
        string dummyReturn = "";
        vector<string> obs;
        //get obs one at a time across row and then pass ALL to make_tuple
        auto obsRow = make_tuple(rowNumber, dummyReturn);
        return &obsRow;
    }
    /** get a variable with meta-data and the dataset stored in it.
         *  This is a node.
         *  @param vName the node or variable name to fetch, default NULL or
         *  @param vNumber the node or variable number to fetch default 0
         *  @return the variable node
         */
    node dataframe::getNode(int vNumber) {
        varsGrp = df[vNumber];
        return varsGrp;
    }


    /** get a range of rows, ie. observation(s) as tuples,
         *  @param the rows to fetch
         *  @return a vector<tuple>, the variable values in the rows (as a
         *                         pointer to a vector of tuple)
         */
    vector<string> dataframe::getRangeOfRows(int start, int ending) {
        vector<string> aRange;
        aRange.push_back("");
        return aRange;
    }

    /** get data range or block from one or more variables (columns) of the
     *  dataframe structure,
     *  @param r1, c1, r2, c2 - the rows and columns to fetch         *
     *  @return a pointer to a block of values for the range selected
     */
    void* dataframe::getDataRange(int r1,int c1,int r2, int c2) {
        vector<vector<string> > aRange;                                                //??? make an array or matrix of strings ?

        return &aRange;
    }

    /** get listing of variable names (column names) of the dataframe.
     *  @param null
     *  @return a vector<string> the variable names as a vector of
     *          strings
     */
    vector<string> dataframe::getColNames() {
        return colNames;
    }

    vector<string> dataframe::getColTypes() {
        return colTypes;
    }

    /** Accessor-get string array of csv data
     *  @param none.
     *  @return fileDataArray the csv file data as a point to a 2D string array.
     */
    void* dataframe::getStrArray(){
        string dataArray[nrows][ncols];
        vector<string> rowData;
        for(unsigned int r = 0; r < nrows;++r) {
            rowData = fetchedStrDataStruct[r];
            for(unsigned int c = 0; c < ncols;++c) {
                dataArray[r][c] = rowData[c];
                cout  << " " << dataArray[r][c];
            }
        }

        return dataArray;
    }


    /** add a row of observations to the dataframe structure tuples,
     *  @param obsRow a pointer to the tuple of observations to add
     *  @return none (void)
     */
    void dataframe::addObsRow(void* obsRow) {

    }

    void dataframe::setColTypes(std::vector<std::string> cTypes) {
        colTypes = cTypes;
    }

    void dataframe::setColNames(vector<string> cNames) {
        colNames = cNames;
    }


    /** add a new Node/variable or (re)set the contents of a Node or variable,
     *  @designnote Consider whether this functionality should be split further
     *        between variable data edit, Node content resets and node add.
     *  @param Node varNode with all the variable meta-data and data,
     *  @param vNumber the position number of the variable. if exists reset, if new add
     *  @return none (void)
     */
    void dataframe::setNode(node varNode, int vNumber) {
        df[vNumber] = varNode;
    }

    /**
     * reset dataframe from external vector<node>
     * an already constructed vector of nodes (variables)
     * @param dframe an intact  vector of nodes from any source
     *
     */
    void dataframe::setDataframe(vector< node> dframe) {
        df = dframe;
    }

    void dataframe::setDfName(string dName){
        dfName = dName;
    }

    /**
     * convert dataframe to a vector of strings
     *
     */
    void convertDfToVStrings(dataframe df) {
        vector<vector<string> > Vstr;

    }

    /** convert a parsed vector of strings to a dataframe of nodes
     *
     *
     */
    void dataframe::convertParsedVStrtoDf(vector< vector<string> > parsedVVS) {
        dataframe df;

    }

    /** load data from a CSV into the dataframe,
     *  @param csvFName name and path of the file to read and import the data from.
     *  @param header a boolean indicating if the first row of CSV contains column names.
     *  @return none (void)
     */
    void dataframe::loadFromCSV(string csvFName, bool header) {
        // get the raw string data, vector<vector<string> > via UtilsCSV
        string frCSV = csvFName;
        bool head = header;
        int rtoline = 0;
        vector<string> cTypes;
        csvToStrArray newCSV(frCSV, head, rtoline);
        fetchedStrDataStruct = newCSV.getStrDataStruct();
        // get the vector<string> list of data types to be applied by column
        cTypes = newCSV.getColTypes();
        colNames = newCSV.getColNames();

        // convert vector of string vectors to array
        string dataArray[nrows][ncols];
        vector<string> rowData;
        for(unsigned int r = 0; r < nrows;++r) {
            rowData = fetchedStrDataStruct[r];
            for(unsigned int c = 0; c < ncols;++c) {
                dataArray[r][c] = rowData[c];
                //cout  << " " << dataArray[r][c];
            }
        }
        // create vectors for nodes
        vector<vector<string> > dataVectors;
        vector<string> colData;
        for(unsigned i = 0; i < nrows; ++i) {
                colData.push_back(" ");
            }
        for(unsigned j = 0; j < ncols; ++j) {
            dataVectors.push_back(colData);
        }

        for(unsigned c = 0; c < ncols; ++c){
            colData = dataVectors[c];
            //cout << "colData assigned to column ok" << endl;
            for(unsigned r = 0; r < nrows; ++r) {
                colData[r] = dataArray[r][c];
            }
            dataVectors[c] = colData;
            cout << (dataVectors[c])[5] << endl;
        }


        // create Node from vectors<type> for each  column and
        // populate columns from Nodes in the generic or blank dataframe
        node varNode[ncols];
        for(unsigned c = 0;c < ncols;++c){
            varNode[c].setVarName("V"+to_string(c));
            varNode[c].setVarType("string");
            varNode[c].setVarDataRows(nrows);
            varNode[c].setVarNumber(c);
            df.push_back(varNode[c]);
        }
        //add the data vector pointer to the nodes in the dataframe
        for(unsigned c = 0;c < ncols;++c){
            df[c].setVarData(&dataVectors[c]);
        }



        //end
    }

    /**
     * readRowsCSV, read a variable element from each row and construct a column vector of
     * a single variable's observation set
     *
     * @param strDStruct CSV derived  string data structure to read from
     * @param nR number of row s (ie. elements ) to be read into the column vector
     * @param colNumber  the variable number (column) of analogous observations
     * @return varVector the vector of variable readings (observations)
     */
    vector<string> dataframe::readRowsSDS(vector<vector<string> > strDStruct, int nR, int colNumber) {
        // vector to contain the obs from column of sDStruct
        vector<string> varVector;
        // populate varVector from csv rows at colNumber
        vector<string> dataRow;
        string currentObs;
        for(unsigned int r = 0; r < nR; ++r) {
            dataRow = strDStruct[r];
            currentObs = dataRow[colNumber];
            varVector.push_back(currentObs);
        }
        cout<< "Created vector " << colNumber << " of length " << varVector.size() << endl;
        for(unsigned int el = 0; el < varVector.size(); ++el) {
            cout << el << "  " << varVector[el]  << endl;
        }
        return varVector;
    }


    /** build a dataframe / Class of vector of variable columns of types string
     *  as vector collection of contents from parsed strings of a specific
     *  observation fields. */
    void dataframe::convertCSVtoDF(vector<vector<string> > sDStruct, int nCSVRows, int nCSVCols) {
        nrows = nCSVRows;
        ncols = nCSVCols;
        vector<string> colVData;
        vector<vector<string>* > nodeVectors;
        vector<string>* ptrColVData;
        cout << "  Number of Rows  " << nrows;
        cout<< "  Number of columns  " << ncols <<endl <<endl;
        /** read each CSV row, into a column vector,
         *  put pointer5 to vector in a node,
         *  put node in the dataframe */
        for(unsigned int i = 0; i < ncols; ++i){
            // i is the current column being read
            // nrows is the number if elements to read in the ith row
            colVData = readRowsSDS(sDStruct, nrows, i);
            // create pointer to variable vector of obs elements,
            ptrColVData = &colVData;
            nodeVectors.push_back(ptrColVData);
        }

        for(unsigned int n = 0; n < ncols; ++n) {
            node varn(nrows, "test", "string", n, nodeVectors[n]);
            df.push_back(varn);
        }
    }

    /** save the dataframe contents (with or without a header line) to a
         *  CSV file,
         *  @param csvFName to save to (defaults to 'datafile').
         *  @param header a boolean to say wther to include column names.
         *  @return none (void)
         */
    void dataframe::saveToCSV(string csvFName) {
        //
    }

    /** display the dataframe as a table or wxGrid structure,
         *  @param none
         *  @return none (void)
         */
    void dataframe::displayDataframe() {
        // output rows as selected elements from each node
        for(unsigned int r = 0; r < nrows; ++r){
            for(unsigned int c = 0; c < ncols; ++c) {
                //print item r of node c, repeat

            }

        }
    }

    /** display the node/variable of the dataframe,
         *  @param varName variable to display by name
         *  @param varNumber variable number to display
         *  @return none (void)
         */
    void dataframe::displayNodeData(int position, string varName) {
        // uses node::displayNode function
    }

    /** convert the full dataframe contents to a string stream,
         *  @param none
         *  @return none (void)
         */
    string dataframe::toStringStream() {
        return "";
    }

