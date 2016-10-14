## Design Notes  

@brief A library, containing a consolidated collection of routines to support R-style Data Structures for C++

###Objective: 

The overall goal is the development of a set of data structures suited particularly to the use of C++ in data analysis. Core to this is the development of a data table structure like the R data.frame.

Perhaps one of the most attractive features in the R language (after the implicit idea vectorization of it's structures and functions) is it's data structures, particularly the dataframe.

This is emulated to a degree in python with the pandas data analysis library. Other interpreted and proprietary statistical environments have approximations or substitutes (like spreadsheets) for dataframes. The use of dataframe like transformational structure have been an obvious part of R packages writtent in C++). A search of the open source C++ template libraried etc has not turned up, for me anyway, the obvious evolution of matrices or lists for C++ programming generally.

Further, the inclusion of categorical data in analyses needs a factor data structure like that in R and an ability to construct dummy variables for linear model development. Currently the implementation is contained in,
  
  - RDataframe7.cpp (classes Node and Dataframe)
  - UtilCSV37.cpp (class UtilCSV with a CSV csvToParse structure and dataStruct structure)
  - Category.cpp (class categoryType with structure categoryLevel)
  
see also the Unit Test Function in main.cpp
  
###Principles and Conception: 
  
Initially a list of vectors was the basic plan in keeping with the R structure. However R lists and C++ STL lists are different enough as to handicape any attempt to mimic R structures in C++. Thus a move tp the data.frame in C++ being a vector of vectors. 

The principal issue is the need to random access the variables (columns) in the data.frame is the C++ implementation. The C++ list is implemented as a sequentially accessed object to allow access for actions on the elements across the list. The random access of individual list members is not implemented in the list structure.

![Class Diagram](Dataframe_Class.svg)

###References and Acknowledgements:
  
for a notable CSV file reading project with same general goal, see Jay Satiro, https://github.com/jay/CSV

  -  R Development Core Team, Eds. "The R Language Definition", https://cran.r-project.org/doc/manuals/r-release/R-lang.html September 12, 2016 14:46p
  -  R Development Core Team, Eds. "Writing R Extensions", https://cran.r-project.org/doc/manuals/r-release/R-exts.html September 5, 2016 17:11p
  -  R Development Core Team, Eds. "R Internals", https://cran.r-project.org/doc/manuals/r-release/R-ints.html September 12, 2016 14:52p
  -  Horstmann, Cay and Timothy A Budd, "Big C++", 2nd Edition, John Wiley & Sons, 2009.
  -  Reese, Greg, "C++ standard library practical tips" Thompson Delmar Learning, Hingham MA 2005.
  -  Galassi, Mark et al. (The GSL Team), GNU Scientific Library Reference Manual Edition 1.16, for GSL Version 1.16, 2013. 
  -  Eddelbuettel, Dirk, Seamless R and C++ Integration with Rcpp, Springer New York 2013.
  -  Lawal, H Bayo, "Categorical data analysis with SAS and SPSS applications", Lawrence Erlbaum Associates, Mahwah NJ 2003.
  -  Pierce, Benjamin C., "Basic Category Theory for Computer Scientists, MIT Boston, 1991.
  -  Agresti,Alan Analysis of Ordinal Categorical Data, John Wiley & Sons, New Jersey, 2010.
  -  "Factors in R". http://www.stat.berkeley.edu/classes/s133/factors.html accessed September 5, 2016 at 05:11pm.
  -  Draper, Norman R; Harry Smith Applied Regression Analysis, Third Edition, Wiley Interscience, New York, 1998.
  -  "Categorical Variable", https://en.wikipedia.org/wiki/Categorical_variable, accessed, September 5, 2016 at 05:22pm.
  -  Powers, Daniel A.; Yu Xie Statistical Methods for Categorical Data Analysis,Academic Press, 1999.
  -  Blasius, Jorg; Michael Greenacre, Visualization of Categorical Data, Academic Press, London, 1998.



###Contacts
  
Author web page, http://crunches-data.appspot.com
Email, medmatix@gmail.com
  
    
Copyright 2016 D.A.York
