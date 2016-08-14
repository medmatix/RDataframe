/*
 * @file: RDataframe07017.cpp
 *
 * @title: An R-type dataframe data-structure class for C++
 *
 * Copyright 2016 David York <david@debian2x8david>
 *
 * @author David York
 * @contributors  no others
 * @date Saturday August 13, 2016
 * @version 0.7017
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
        string getDataFrameName() {
            return dfName;
        }

        void createObsDataframe() {
        }

        list<Node> getDataframe() {
            return dataframe;
        }

        void* getObs(int rowNumber) {
            string dummyReturn = "";
            //get obs one at a time across row and then pass ALL to make_tuple
            auto obsRow = make_tuple(rowNumber, dummyReturn);
            return &obsRow;

        }

        vector<string> getRangeRows() {
            vector<string> aRange;
            aRange.push_back("");
            return aRange;
        }

        vector<string> getVarNames() {
            return colNames;
        }

        Node getNode(string vName= "", int vNumber = 0) {
            Node variable;
            return variable;
        }

        void* getDataRange(int r1,int c1,int r2, int c2) {
            vector<string> aRange;
            aRange.push_back("");
            return &aRange;
        }

        void addObsTuple() {
        }

        void setNodeData() {
        }

        void loadFromCSV() {
        }

        void saveToCSV() {
        }

        void displayDataframe() {
        }

        void displayNodeData() {
        }

        string toStringStream() {
            return "";
        }
};


int main(int argc, char **argv)
{


  return 0;
}

// boost::any_cast<int>
