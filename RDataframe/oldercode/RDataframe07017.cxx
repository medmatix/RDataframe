/*
 * @file: RDataframe07019.cpp
 *
 * @title: An R-type dataframe data-structure class for C++
 *
 * Copyright 2016 David York <david@debian2x8david>
 *
 * @author David York
 * @contributors  no others
 * @date Saturday August 13, 2016
 * @version 0.7019
 *
 * @description This creates a datatype "dataframe modeled on the R language datatype. Initial memory order is column major.
 *
 * @licence: This program is free software; you can redistribute it
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
 *
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

class Node {
    protected:
        string varName;
        string varType;
        int varNumber;
        void* ptrData;

	public:
        Node() {
            varName = "";
            varType = "";
            varNumber = 0;
            ptrData = nullptr;
        }

        Node(string vName, string vType, int vNumber, void* pVData) {
            varName = vName;
            varType = vType;
            varNumber = vNumber;
            ptrData = pVData;
        }

        Node(string vName, string vType, int vNumber, void* &pAData) {
            varName = vName;
            varType = vType;
            varNumber = vNumber;
            ptrData = &pAData;
        }

        tuple<string, string, int, void*> getNodeInfo() {
            return make_tuple(varName, varType, varNumber, ptrData);
        }

        void* getVarDataRange(int start, int ending) {
            return ptrData;
        }

        void* getVarData() {
            return ptrData;
        }

        string getVarName() {
            return varName;
        }

        string getVarType() {
            return varType;
        }

        int getVarNumber() {
            return varNumber;
        }

        void setVarData(void* vData) {
            ptrData = vData;
        }

        void setVarName(string vName) {
            varName = vName;
        }

        void setVarType(string vType) {
            varType = vType;
        }

        void setVarNumber(int vNumber) {
            varNumber = vNumber;
        }

		void displayNode() {

		}

		void displayName_Type() {}

		string to_String() {
         string strVarName = varName;
			return strVarName;
		}

		/*sstream toStringStream() {
		    sstream nodeStream="";
		    return nodeStream;

		}*/
};

class Dataframe {
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
        Dataframe() {
            nrows = 0;
            ncols = 0;
            colNames.push_back("");
            Node variable;
        }

        Dataframe(Node varNode) {
            ncols = 0;
            nrows = 0;
            colNames.push_back(varNode.getVarName());
            variable = varNode;
        }

        Dataframe(string s, int r, int c) {
            dfName = s;

        }

        Dataframe(string s1, string s2, int r, int c) {
        }


        /** Dataframe methods     */

        /** get the dataframe name,
         *  @returns a string with the dataframe's name
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
         *  @return a pointer to the tuple conta ining variable values in the
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
         *  @return vector<tuple>, the variable values in the rows (as a pointer to a vector
         *                           of tuple)
         */
        vector<string> getRangeRows() {
            vector<string> aRange;
            aRange.push_back("");
            return aRange;
        }

        /** get list of variable names (column names) of the dataframe.
         *  @param null
         *  @return vector<string> varNames, the variable names as a vector of
         *          strings
         */
        vector<string> getVarNames() {
            return colNames;
        }

        /** get a variable with meta-data and the dataset stored in it.
         *  This is a node.
         *  @param vName the node or variable name to fetch, default NULL, or
         *         vNumber the node or variable number to fetch default 0
         *  @return the variable node
         */
        Node getNode(string vName= "", int vNumber = 0) {
            Node variable;
            return variable;
        }

        /** get data range or block from one or more variables (columns) of the
         *  dataframe structure,
         *  @param the rows and columns to fetch
         *         r1, c1, r2, c2
         *  @return a pointer to a block of values for the range selected
         */
        void* getDataRange(int r1,int c1,int r2, int c2) {
            vector<string> aRange;
            aRange.push_back("");
            return &aRange;
        }

        /** add a row of observations to the dataframe structure tuples,
         *  @param the tuple of observations to add
         *  @return none (void)
         */
        void addObsTuple(void* obsRow) {
        }

        /** add a new Node/variable or (re)set the contents of a Node or variable,
         *  @note Consider whether this functionality should be split further
         *        between variable data edit, Node content resets and node add.
         *  @param Node varNode with all the variable meta-data and data,
         *         vNumber, the position number of the variable. if exists,
         *                  reset, if new add
         *  @return none (void)
         */
        void setNodeData(Node varNode, int vNumber) {
        }

        /** load data from a CSV into the dataframe,
         *  @param csvFName, this name and path of the file to read and import
         *                  the data from
         *         header, a boolean indicating if the first row of CSV
         *                 contains column names
         *  @return none (void)
         */
        void loadFromCSV(string csvFName, bool header) {
        }

        /** save the dataframe contents (with or without a header line) to a
         *  CSV file,
         *  @param csvFName to save to (defaults to 'datafile')
         *         header a boolean to say wther to include column names
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
         *         varNumber variable number to display
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
 *  The Unit Test suite for the Node and Dataframe classes
 *  @param argc, an int argument (optional)
 *         argv, a character array
 *  @return an int, 0 if runs successfully (ie. no errors)
 */
int main(int argc, char **argv)
{


  return 0;
}

// boost::any_cast<int>
