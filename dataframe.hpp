#ifndef DATAFRAME_HPP_INCLUDED
#define DATAFRAME_HPP_INCLUDED

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

#include "csvToStrArray.hpp"
#include "node.hpp"



class dataframe {
protected:
    int nrows;
    int ncols;
    std::string dfName;
    node varsGrp;
    std::vector<node> df;
    std::vector<std::vector<std::string> > fetchedStrDataStruct;
    std::vector<std::string> colNames;
    std::vector<std::string> colTypes;

    void* obsDataFrame = nullptr;
    std::vector<std::string> obsRowNames;
public:

    dataframe();
    dataframe(node varNode);
    dataframe(std::string s, int r, int c);
protected:
    std::vector<std::string> createTypesVector();
    void createObsDataframe();
    boost::any createObsTuple();

public:
    std::vector<node> getDataframe();
    std::string getDataFrameName();
    void* getObs(int rowNumber);
    std::vector<std::string>getColTypes();
    std::vector<std::string>getColNames();
    void setColTypes(std::vector<std::string> cTypes);
    void setColNames(std::vector<std::string> cNames);
    node getNode(int vNumber = 0);
    std::vector<std::string> getRangeOfRows(int start, int ending);
    void* getDataRange(int r1,int c1,int r2, int c2);
    void* getStrArray();
    void addObsRow(void* obsRow);
    void setDfName(std::string);
    void setNode(node varNode, int vNumber);
    void setDataframe(std::vector<node> dframe);
    void convertDfToVStrings(dataframe df);
    std::vector<std::string> readRowsSDS(std::vector<std::vector<std::string> > strDStruct,int nCSVRows, int colNumber);
    void convertParsedVStrtoDf(std::vector< std::vector<std::string> > parsedVVS);
    void loadFromCSV(std::string csvFName, bool header);
    std::vector<std::vector<std::string> > makeDataFrame (std::vector<std::vector<std::string> > intStrDStruct);
    void saveToCSV(std::string csvFName);
    void convertCSVtoDF(std::vector<std::vector<std::string> > strCSVStruct, int nCSVRows, int nCSVCols);
    void displayDataframe();
    void displayNodeData(int position=0, std::string varName="");
    std::string toStringStream();
};



#endif // DATAFRAME_HPP_INCLUDED
