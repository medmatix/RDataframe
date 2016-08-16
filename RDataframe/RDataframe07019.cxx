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
//#include <boost/any.hpp>

using namespace std;

/**
 * The Node Class to contain a variable, it's meta-data and it's data,
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

        /** constructor all meta data for variable and data as pointer to an array */
        Node(string vName, string vType, int vNumber, void* &pAData) {
            varName = vName;
            varType = vType;
            varNumber = vNumber;
            ptrData = &pAData;
        }

        /** the Node class methods */

        /** create a tuple to return all node/variable information
         *  @param none
         *  @return a tuple, of metadata and reference to the variable data,
         *          consists of the variable name (string),variable type (string)
         *          the variable number of position intended in the dataframe
         *          (int) and a pointer to the variable data itself
         */
        tuple<string, string, int, void*> getNodeInfo() {
            return make_tuple(varName, varType, varNumber, ptrData);
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

        /** set the variable data, with a pointer to the data vector
         *  @param pointer to data
         *  @return none (void)
         */
        void setVarData(void* vData) {
            ptrData = vData;
        }

        /** get the variable Name (node meta-datum varName)
         *  @param the variable name (string)
         *  @return none (void)
         */
        void setVarName(string vName) {
            varName = vName;
        }

        /** get the variable type (node meta-datum varType)
         *  @param the variable type (string)
         *  @return none (void)
         */
        void setVarType(string vType) {
            varType = vType;
        }

        /** get the variable (position)number (node meta-datum varNumber)
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

		}

        /** display the variable name and type
         *  @param none
         *  @return none (void)
         */
		void displayName_Type() {}

        /** convert the node data to a string
         *  @param none
         *  @return the node as a continuous string (potentially a string stream
         */
		string to_String() {
         string strVarName = varName;
			return strVarName;
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
    cout << "Unit Test Suite:" << endl;

    /** Node tests */
    /** test default constructors*/
    Node variable1;
    ;

    /** test full constructors */

    /** test various class methods */


    /** Dataframe tests */
    /** test default constructors*/
    Dataframe dfTest;

    /** test full constructors */

    /** test various class methods */

  return 0;
}

// boost::any_cast<int>
