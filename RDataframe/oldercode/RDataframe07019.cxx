/** \file
 * \mainpage R-Dataframe
 * \section Program Information and Credits
 *
 * Source File:
 * *Dataframe07019.cpp*
 *
 * ##An R-type dataframe data-structure class for C++
 *
 * @author David York
 * @date Saturday August 13, 2016
 * @version 0.7019
 *
 * \brief
 * This creates a datatype "dataframe" modeled on the R language datatype. Initial memory order is column major.
 *
 *
 * \subsection License
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 * &copy; 2016 David York
 * \page "Design Notes"
 *  \ref ![UML](./Dataframe_Class.svg)
 */

#include <typeinfo>
#include <cxxabi.h>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>
#include <array>
#include <initializer_list>
//#include <boost/any.hpp>

using namespace std;

/**
 * Node Class to contain a variable, it's meta-data and it's data,
 *  (or rather a pointer to a vector containing the data
 */
class Node {
    //the Node meta-data fields
    protected:
        /** the variable name, meta-data, unique to each node */
        string varName;
        /** the variable type, meta-data, tracks to type of the data in the vector
         * pointed to */
        string varType;
        /** the variable number, meta-data unique to each node, tracks the intended
         * position in the dataframe  */
        int varNumber;
        /** a pointer to the start in memory of the vector for variable data*/
        void* ptrData;
        int nrows;

	public:
	    /** default constructor */
        Node() {
            varName = "";
            varType = "";
            varNumber = 0;
            ptrData = nullptr;
        }

        /** constructor all meta data for variable and data as pointer to a vector */
        Node(string vName, string vType, int vNumber, void* pVData) {
            varName = vName;
            varType = vType;
            varNumber = vNumber;
            ptrData = pVData;
        }



        /** the Node class methods */

        /** create a tuple to return all node/variable information
         *  @param none
         *  @return a tuple, of metadata and reference to the variable data,
         *          consists of the variable name (string),variable type (string)
         *          the variable number of position intended in the dataframe
         *          (int) and a pointer to the variable data itself
         */
        tuple<string, string, int, int void*> getNodeInfo() {
            return make_tuple(varName, varType, varNumber, nrows, ptrData);
        }

        /** get a range of variable data from the node vector
         *  @param start - the starting index for the range of data.
         *  @param the ending index for the range
         *  @return a pointer to the start of memory containing the data range
         */
        void* getVarDataRange(int start, int ending) {
            return ptrData;
        }

        /** get a all of the variable data from the node vector
         *  @param none
         *  @return a pointer to the start of memory containing the data vector
         */
        void* getVarData() {
            return ptrData;
        }

        /** get the variable name (node meta-datum varName)
         *  @param none
         *  @return the variable name (string)
         */
        string getVarName() {
            return varName;
        }

        /** get the variable type (node meta-datum varType)
         *  @param none
         *  @return the variable type (string)
         */
        string getVarType() {
            return varType;
        }

        /** get the variable (position) number (node meta-datum varNumber)
         *  @param none
         *  @return the variable number (int)
         */
        int getVarNumber() {
            return varNumber;
        }

        /** get nrows, the number of data rows in the Node vector
         *  @param none
         *  @return nrows, an int with the number of data rows in vector
         */
        int getNRows() {
            return nrows;
        }

        /** set the variable data, with a pointer to the data vector
         *  @param r, int with the number of rows in data vector (i.e its size)
         *  @param vName, string with variable name
         *  @param vType, string with variable type
         *  @param vNumber, int with variable (position number
         *  @param vData, pointer to data vector
         *  @return none, (void)
         */
        void setNodeContent(int r; string vName, string vType, int vNumber, void* pvData) {
            varName = vName;
            varType = vType;
            varNumber = vNumber;
            ptrData = pvData;
            nrows = r;
        }

        /** set the variable data, with a pointer to the data vector
         *  @param r, the number of rows/elements in data vector
         *  @return none (void)
         */
        void setVarDataRows(int = r) {
            nrows = r;
        }

        /** set the variable data, with a pointer to the data vector
         *  @param pointer to data
         *  @return none (void)
         */
        void setVarData(void* vData) {
            ptrData = vData;
        }

        /** set the variable Name (nvector<int> year {data[0]};ode meta-datum varName)
         *  @param the variable name (string)
         *  @return none (void)
         */
        void setVarName(string vName) {
            varName = vName;
        }

        /** set the variable type (node meta-datum varType)
         *  @param the variable type (string)
         *  @return none (void)
         */
        void setVarType(string vType) {
            varType = vType;
        }

        /** set the variable (position)number (node meta-datum varNumber)
         *  @param the variable type (string)
         *  @return none (void)
         */
        void setVarNumber(int vNumber) {
            varNumber = vNumber;
        }

        /** display the whole node, meta-data and data
         *  @param none
         *  @return none (void)
         */
		void displayNode() {
		    cout << "name: " << varName << endl;
		    cout << "type: " << varType << endl;
		    cout << "position number: " << varNumber << endl;
		    cout << "data address: " << ptrData << endl;
		    cout << "first data point value: " << (*(vector<int>*)ptrData)[0] << endl;

		}

        /** display the variable name and type
         *  @param none
         *  @return none (void)
         */
		void displayName_Type() {
		    cout << "Variable Name: " << varName << endl;
            cout << "Variable Type: " << varType << endl;
		}

        /** convert the node data to a string
         *  @param none
         *  @return the node as a continuous string (potentially a string stream
         */
		string toString() {
            string strVarName = varName;
            string strVarType = varType;
            string strVarNumber =  to_string(varNumber);
            string strVarData = "";
            int dataElement;

            for(int i = 0; i<12; ++i) {
                dataElement = (*(vector<int>*)ptrData)[i];
                strVarData = strVarData+" "+to_string(dataElement);
            }
			string retStr = strVarName+" "+strVarType+" "+strVarNumber+" "+strVarData;
			return retStr;
		}
};

/**
 * The Dataframe class to present the R like structure to use in data analysis
 */
class Dataframe {
/** the Dataframe meta-data fields */
protected:
    int nrows;
    int ncols;
    string dfName;
    list<Node> dataframe;
    Node variable;
    vector<string> colNames;
    void* obsDataFrame = nullptr;
    vector<string> obsRowNames;

public:
        /** the default constructor */
        Dataframe() {
            nrows = 0;
            ncols = 0;
            colNames.push_back("");
            Node variable;
        }

        /** a constructor with the first variable/Node initializes rows and columns to (0,0)*/
        Dataframe(Node varNode) {
            ncols = 0;
            nrows = 0;
            colNames.push_back(varNode.getVarName());
            variable = varNode;
        }

        /** constructor with dataframe name, number of rows and number of columns in table */
        Dataframe(string s, int r, int c) {
            dfName = s;
            nrows = r;
            ncols = c;
        }


        /** Dataframe class methods     */

        /** get the dataframe name,
         *  @param none
         *  @return a string with the dataframe's name
         */
        string getDataFrameName() {
            return dfName;
        }

        /** create a table of observations from the dataframe listing variable
         *  observation(s) (values) as tuples,
         *  @param none
         *  @return none (void)
         */
        void createObsDataframe() {
        }

        /** get the whole dataframe as a list of nodes
         *  @param none
         *  @return dataframe, ie. a list of nodes which is the dataframe itself
         */
        list<Node> getDataframe() {
            return dataframe;
        }

        /** get observations from a row of the dataframe structure
         *  observation(s) as tuples,
         *  @param the row to fetch
         *  @return a pointer to the tuple containing variable values in the
         *          row
         */
        void* getObs(int rowNumber) {
            string dummyReturn = "";
            //get obs one at a time across row and then pass ALL to make_tuple
            auto obsRow = make_tuple(rowNumber, dummyReturn);
            return &obsRow;
        }

        /** get a range of rows, ie. observation(s) as tuples,
         *  @param the rows to fetch
         *  @return a vector<tuple>, the variable values in the rows (as a
         *                         pointer to a vector of tuple)
         */
        vector<string> getRangeRows() {
            vector<string> aRange;
            aRange.push_back("");
            return aRange;
        }

        /** get list of variable names (column names) of the dataframe.
         *  @param null
         *  @return a vector<string> the variable names as a vector of
         *          strings
         */
        vector<string> getVarNames() {
            return colNames;
        }

        /** get a variable with meta-data and the dataset stored in it.
         *  This is a node.
         *  @param vName the node or variable name to fetch, default NULL or
         *  @param vNumber the node or variable number to fetch default 0
         *  @return the variable node
         */
        Node getNode(string vName= "", int vNumber = 0) {
            Node variable;
            return variable;
        }

        /** get data range or block from one or more variables (columns) of the
         *  dataframe structure,
         *  @param r1, c1, r2, c2 - the rows and columns to fetch         *
         *  @return a pointer to a block of values for the range selected
         */
        void* getDataRange(int r1,int c1,int r2, int c2) {
            vector<string> aRange;
            aRange.push_back("");
            return &aRange;
        }

        /** add a row of observations to the dataframe structure tuples,
         *  @param obsRow a pointer to the tuple of observations to add
         *  @return none (void)
         */
        void addObsTuple(void* obsRow) {
        }

        /** add a new Node/variable or (re)set the contents of a Node or variable,
         *  @designnote Consider whether this functionality should be split further
         *        between variable data edit, Node content resets and node add.
         *  @param Node varNode with all the variable meta-data and data,
         *  @param vNumber the position number of the variable. if exists reset, if new add
         *  @return none (void)
         */
        void setNodeData(Node varNode, int vNumber) {
        }

        /** load data from a CSV into the dataframe,
         *  @param csvFName name and path of the file to read and import the data from.
         *  @param header a boolean indicating if the first row of CSV contains column names.
         *  @return none (void)
         */
        void loadFromCSV(string csvFName, bool header) {
        }

        /** save the dataframe contents (with or without a header line) to a
         *  CSV file,
         *  @param csvFName to save to (defaults to 'datafile').
         *  @param header a boolean to say wther to include column names.
         *  @return none (void)
         */
        void saveToCSV(string csvFName) {
        }

        /** display the dataframe as a table or wxGrid structure,
         *  @param none
         *  @return none (void)
         */
        void displayDataframe() {
        }

        /** display the node/variable of the dataframe,
         *  @param varName variable to display by name
         *  @param varNumber variable number to display
         *  @return none (void)
         */
        void displayNodeData() {
        }

        /** convert the full dataframe contents to a string stream,
         *  @param none
         *  @return none (void)
         */
        string toStringStream() {
            return "";
        }
};

/**
 * \page "Unit Tests"
 *  \section Unit Test Documentation
 * The main() function is a non-member function related to both the Node class
 * and the Dataframe class. When complete it will have called all functions of
 * the two classes as well as any external calls to the CSVUtils library in
 * order to test import of disk file datasets into the Datarame objects.
 *
 * \fn the main function
 *  The Unit Test suite for the Node and Dataframe classes
 *  @param argc, an int argument (optional)
 *  @param argv, a character array
 *  @return an int, 0 if runs successfully (ie. no errors)
 */
int main(int argc, char **argv)
{
    //Test Suite Heading
    cout << "  Unit Test Suite:" << endl;
    cout << "  ================" << endl << endl;
    cout << "Getting test data. . ." << endl << endl;
    /** Make working data arrays for unit tests
    *   from AirPassengers.csv, a base R dataset */
    initializer_list<int> data[13];
    initializer_list<string> colHead = {"Date","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    data[0] = {1949, 1950, 1951, 1952, 1953, 1954, 1955, 1956, 1957, 1958, 1959, 1960};
    data[1] = {112, 115, 145, 171, 196, 204, 242, 284, 315, 340, 360, 417};
    data[2] = {118, 126, 150, 180, 196, 188, 233, 277, 301, 318, 342, 391};
    data[3] = {132, 141, 178, 193, 236, 235, 267, 317, 356,362, 406, 419};
    data[4] = {129, 135, 163, 181, 235, 227, 269, 313, 348, 348, 396, 461};
    data[5] = {121, 125, 172, 183, 229, 234, 270, 318, 355, 363, 420, 472};
    data[6] = {135, 149, 178, 218, 243, 264, 315, 374, 422, 435, 472, 535};
    data[7] = {148, 170, 199, 230, 264, 302, 364, 413, 465, 491, 548, 622};
    data[8] = {148, 170, 199, 242, 272, 293, 347, 405, 467, 505, 559, 606};
    data[9] = {136, 158, 184, 209, 237, 259, 312, 355, 404, 404, 463, 508};
    data[10] = {119, 133, 162, 191, 211, 229, 274, 306, 347, 359, 407, 461};
    data[11] = {104, 114, 146, 172, 180, 203, 237, 271, 305, 310, 362, 390};
    data[12] = {118, 140, 166, 194, 201, 229, 278, 306, 336, 337, 405, 432};
    vector<string> cnames {colHead};
    vector<int> year {data[0]};
    vector<int> jan {data[1]};
    vector<int> feb {data[2]};
    vector<int> mar {data[3]};
    vector<int> apr {data[4]};
    vector<int> may {data[5]};
    vector<int> jun {data[6]};
    vector<int> jul {data[7]};
    vector<int> aug {data[8]};
    vector<int> sep {data[9]};
    vector<int> oct {data[10]};
    vector<int> nov {data[11]};
    vector<int> dec {data[12]};

//    cout << "Number of columns: " << ncols <<< endl;
//    int nrows = colhead.length
    //cout << "Number of columns: " << ncols <<< endl;

    /** Node tests */
    string vName;
    string vType;
    int vNumber;
    void* pVData;
    /** test default constructors*/
    vName = "Date";
    vType = "int";
    vNumber = 0;
    pVData =&year;
    Node variable1;
    variable1.setNodeContent(vName, vType, vNumber, pVData);
    cout << "NODE #: " << vNumber << endl;
    variable1.displayNode();
    cout << endl;
    variable1.displayName_Type();
    cout << endl << endl;


    /** test full constructors */
    vName = "Jan";
    vType = "int";
    vNumber = 1;
    pVData = &jan;
    Node variable2(vName, vType, vNumber, pVData);
    cout << "NODE #: " << vNumber << endl;
    variable2.displayNode();
    cout << endl << endl;




    /** test various class methods */
    /**    Setters */
    cout << "testing setters . . ."<<endl;
    cout<<endl;
    variable2.setVarName("other");
    variable2.setVarType("long");
    cout << "show adjusted name and type"<< endl;
    variable2.displayName_Type();
    cout<<endl;
    variable2.setVarNumber(3),
    cout << "changed position number and show the whole amended node," << endl;
    variable2.displayNode();
    cout<<endl;
    cout << "return comtemts to original and display the node again." <<endl;
    variable2.setNodeContent(vName, vType, vNumber, pVData);
    cout << "NODE #: " << vNumber << endl;
    variable2.displayNode();
    cout << endl << endl;

    cout << "Check Node.toString() function " << endl << variable2.toString() << endl;

    /**    Getters */

    /** Dataframe tests */
    /** test default constructors*/
    Dataframe dfTest;

    /** test full constructors */

    /** test various class methods */

  return 0;
}

// boost::any_cast<int>
