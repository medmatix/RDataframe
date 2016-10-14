/**\file
 * \page "Unit Tests"
 *
 * Source: main.cpp (current working version of test code here)
 *
 * **Unit tests for C++ classes for Category datatype, RDataframe7
 *         datatype and csvToStrArray37 CSV Manipulation**
 *
 *
 * @author David York <david@debian2x8david>
 * @date Sunday September 4, 2016
 * @version 0.3
 *
 * @brief This is the main() module for Unit testing of the classes related to
 *        the RDataframe data type ( Dataframe )and relevant other code including
 *        that for the category data type the node data type ( Node ) and the CSV
 *        file utilities ( csvToStrArray ).
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
#include "csvToStrArray.hpp"
#include "category.hpp"

using namespace std;

/**
 * \page "Unit Tests"
 *  @brief The main() function is a non-member function related to testing of the
 *  classes  Node, RDataframe, Category, csvToStrArray
 * \fn "the main function"
 *  The Unit Test suite for the Node and Dataframe classes
 *  @param argc, an int argument (optional)
 *  @param argv, a character array
 *  @return an int, 0 if runs successfully (ie. no errors)
 */

int main(int argc, char **argv)
{
/**
 * \page " "
 * \section "RDataframe Unit Tests"
 *  \subsection "Test Documentation"
 * This part of the main() function is related to both the Node class
 * and the Dataframe class. When run is complete it will have called all
 * functions of the two classes as well as any external calls to the UtilsCSV
 * library in order to test import of disk file datasets into the Dataframe
 * objects.
 */

    cout << "   Dataframe Unit Test Suite:" << endl;
    cout << "   =========================" << endl << endl;
    cout << "       Getting test data. . ." << endl << endl;
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


    /** NODE TESTS */
    cout << endl << "  Node Specific Tests " << endl;
    cout << "  ------------------- " << endl << endl;
    string vName;
    string vType;
    int vNumber;
    void* pVData;
    int r;

    /** test default constructors*/
    vName = "Date";
    vType = "int";
    vNumber = 0;
    pVData =&year;
    r = year.size();
    node variable1;
    variable1.setNodeContent(r, vName, vType, vNumber, pVData);
    cout << " NODE #: " << vNumber << endl;
    variable1.displayNode();
    cout << endl;

 /** test full constructors */
    vName = "Jan";
    vType = "int";
    vNumber = 1;
    pVData = &jan;
    r = jan.size();

    node variable2(r, vName, vType, vNumber, pVData);
    cout << "NODE #: " << vNumber << endl;
    variable2.displayNode();
    cout << endl << endl;




    /** test various class methods */
    /**    Setters */
    cout << " testing setters . . ."<<endl;
    cout << "   change variable name and type" << endl;
    cout<<endl;
    variable2.setVarName("other");
    variable2.setVarType("long");
    cout << "   show new or adjusted name and type"<< endl;
    variable2.displayName_Type();
    cout << "   change position number " <<endl;
    variable2.setVarNumber(3);
    variable2.setVarDataRows(30);
    cout << "   show changed position number and nrows and display the whole amended node," << endl;
    variable2.displayNode();
    cout<<endl;

    r = jan.size();
    cout << "  return contents to original and display the node again." <<endl;
    variable2.setNodeContent(r, vName, vType, vNumber, pVData);
    cout << " show meta-data and data vector now . . " << endl;
    cout << " NODE #: " << vNumber << endl;
    variable2.displayNode();
    cout << endl << endl;

    cout << " Check Node.toString() function, " << endl << variable2.toString() << endl << endl;

    /**    Getters */
    cout << " Check All the Getters," << endl;
    cout << "   getting variable data pointer: " << variable1.getVarData() << endl;
    cout << "   getting variable name:         " << variable1.getVarName() << endl;
    cout << "   getting variable type:         " << variable1.getVarType() << endl;
    cout << "   getting variable position number: " << variable1.getVarNumber() << endl;
    cout << "   getting number of variable data rows: " << variable1.getNRows() << endl<< endl;
    cout << "   get variable data range:          " << endl;
    void* retDataPtr = variable2.getVarDataRange(4,10);
    vector<int>* extrIntDataPtr = ((vector<int>*)retDataPtr);
    cout << "returned recast vector size: " << (*extrIntDataPtr).size() << endl;
    vector<int> extrData = (*extrIntDataPtr);
    cout << "returned recast vector size: " << extrData.size() << endl;
    for(unsigned int i = 0; i < extrData.size(); ++i) {
                    cout << extrData[i] << endl;
                }
    cout << endl;


    /** Testing different data types
     *  string */
    cout << endl << endl;
    cout << "  Create and test a string variable " << endl << endl;
    initializer_list<string> strData = {"Date","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    vector<string> months {strData};
    vName = "Month";
    vType = "string";
    vNumber = 0;
    pVData = &months;
    r = months.size();

    node variable5s(r, vName, vType, vNumber, pVData);
    cout << "NODE #: " << vNumber << endl;
    variable5s.displayNode();

    cout << endl;
    cout << "extract some elements fro the string variable vector" << endl;
    retDataPtr = variable5s.getVarDataRange(4,10);
    vector<string>* extrStrDataPtr = ((vector<string>*)retDataPtr);
    cout << "returned recast vector size: " << (*extrStrDataPtr).size() << endl;
    vector<string> extrStrData = (*extrStrDataPtr);
    cout << "returned recast vector size: " << extrStrData.size() << endl;
    for(unsigned int i = 0; i < extrStrData.size(); ++i) {
        cout << extrStrData[i] << endl;
    }
    cout << endl << endl;


    /** double type */
    cout << "  Create and test a double variable" << endl << endl;
    initializer_list<double> dblData {2.3413,5.23, 23.56, 198.0, 7.11042, 734.9992, 19.1945, 3.1415962, 45, 30.2, 7565.11, 629.023};
    vector<double> rndNumbs {dblData};
    vName = "randoms";
    vType = "double";
    vNumber = 0;
    pVData = &rndNumbs;
    r = rndNumbs.size();

    node variable5d(r, vName, vType, vNumber, pVData);
    cout << "NODE #: " << vNumber << endl;
    variable5d.displayNode();

    cout << endl;
    cout << "extract some elements fro the double variable vector" << endl;
    retDataPtr = variable5d.getVarDataRange(4,10);
    vector<double>* extrDblDataPtr = ((vector<double>*)retDataPtr);
    cout << "returned recast vector size: " << (*extrDblDataPtr).size() << endl;
    vector<double> extrDblData = (*extrDblDataPtr);
    cout << "returned recast vector size: " << extrDblData.size() << endl;
    for(unsigned int i = 0; i < extrDblData.size(); ++i) {
        cout << extrDblData[i] << endl;
    }





    cout << endl << endl;
    cout << "  ************************************* " << endl <<endl;
    /** DATAFRAME TESTS */
    /** test default constructors*/
    cout << "  Dataframe SpecificTests "<< endl;
    cout << "  ----------------------- " <<endl << endl;
    dataframe dfTest;
    cout << "  dfTest an empty dataframe constructed, awaits meta-data and data variables " << endl<<endl;

    /** test full constructors */

    /** test various class methods */

    cout << endl << "  ************************************* " << endl;



/**
 * \section "csvToStrArray Unit Tests"
 *  \subsection "Test Documentation"
 * This part of the main() function is related to both the UtilCSB class
 * and thefunctions there-in. When the run is complete it will have called
 * all functions of the class as well as any external calls in
 * order to test import of disk file datasets.
 */

    /** csvToStrArray TESTS*/
    string frmCSV ="./data/AirPassengersNoHeader.csv";
    bool hHeader = true;
    csvToStrArray Airpass(frmCSV, hHeader);
    cout << "  csvToStrArray Unit Test Suite:" << endl;
    cout << "  =======================" << endl<< endl;
    cout << " Getting test data. . ."<< endl<<endl;
    cout << " no. cols: " << Airpass.getNcols() << endl;
    cout << " no. rows: " << Airpass.getNrows() << endl;
    Airpass.displayInternCSV();
    Airpass.displayColNames();
    Airpass.displayStrDataStruct();
    vector<vector<string> > strDStruct = Airpass.getStrDataStruct();
    Airpass.writeCSV(strDStruct, "datafile.csv");
    vector<string> newCols;
        newCols.push_back("Date");
        newCols.push_back("Jan");
        newCols.push_back("Feb");
        newCols.push_back("Mar");
        newCols.push_back("Apr");
        newCols.push_back("May");
        newCols.push_back("Jun");
        newCols.push_back("Jul");
        newCols.push_back("Aug");
        newCols.push_back("Sep");
        newCols.push_back("Oct");
        newCols.push_back("Nov");
        newCols.push_back("Dec");
    Airpass.setColNames(newCols);
    Airpass.displayInternCSV();
    Airpass.displayColNames();
    Airpass.displayStrDataStruct();
    vector<vector<string> > sDS = Airpass.getStrDataStruct();
    Airpass.writeCSV(Airpass.getStrDataStruct(), "./data/newHeader.csv");
    cout << endl << endl;


    // Now make a df from the string data structure and stor in a data frame
    dataframe dfAirpass("dfAirPass", 11, 13);
    cout << "  New dataframe:  " << dfAirpass.getDataFrameName() << endl<< endl;
    cout << "  old string frame: again " << endl << endl<< endl;
    Airpass.displayStrDataStruct();
    vector<vector<string> > sDStruct = sDS;
    // read nR = 11 elements into column colNumber = 12
   /* dfAirpass.readRowsSDS(sDS, 11, 5);
    // read all 11 elements of all 12 columns
    dfAirpass.convertCSVtoDF(sDStruct, 11, 13);
    int nrows = Airpass.getNrows();
    int ncols = Airpass.getNcols();
    */

    void* anyPtr;
    int ncols = Airpass.getNcols();
    dfAirpass.loadFromCSV("./data/AirPassengersNoHeader.csv", true);
    for(unsigned c = 0; c < ncols; ++c) {
        cout << "  Node " << c << " Pointer retrieved: " << (dfAirpass.getNode(c)).getPtrData() << endl;
        cout << "  Node number: " << (dfAirpass.getNode(c)).getVarNumber()<< endl;
        cout << "  Node name: " << (dfAirpass.getNode(c)).getVarName()<< endl<<endl<< endl;
    }
    dfAirpass.displayDataframe();
    void* voidPtr = (dfAirpass.getNode(3)).getPtrData();
    cout << "  Node Variable Name: " << dfAirpass.getNode(3).getVarName() << endl;
    cout << "  Node " << 3 << " Pointer retrieved: " << voidPtr << endl << endl;
    const vector<string>* obsptr;
    obsptr = static_cast<vector<string>* >(voidPtr);

    /** Category data type TESTS */
    cout << endl<<endl<<endl;
    cout << "  ==============================" << endl;
    cout << "  CATEGORY type Unit Test Suite:" << endl;
    cout << "  ==============================" << endl<< endl;
    cout << endl<<endl;




    cout << "   All Tests Completed"<< endl;

    return 0;
}
