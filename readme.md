# Dataframe
## An active data table class 
### As an  R style data.frame class, with methods, for C plus plus. 
   
### Overview and Statement of purpose (goal development)
see [Project page](https://medmatix.github.io/RDataframe/)

Perhaps one of the most attractive features in the R language (after the implicit idea vectorization of it's structures and functions) is it's data structures, particularly the dataframe.

This is emulated to a degree in python with the pandas data analysis library. Other interpreted and proprietary statistical environments have approximations or substitutes (like spreadsheets) for dataframes. The use of dataframe like transformational structure have been an obvious part of R packages writtent in C++). A search of the open source C++ template libraried etc has not turned up, for me anyway, the obvious evolution of matrices or lists for C++ programming generally.

This project has the goal of developing an R-like dataframe class for similar applications for analysis of data written entirely in C++. 

The necessary building blocks of this dataframe analog are a Variable composite data structure including vector class for the raw data, for the columns of the dataframe, and a list class to contain the variable objects. Of note, R arrays are column major memory structures, so this is a basic adaptation required to privide at least a virtual variable oriented structure.

The R dataframe is, as well, a list derivative with vectors for the columns as elements of the list. The base reference to the  elements (rows and columns) is the usual numeric endices. However, associative reference with variable (column) and observation (row) also a feature.

As I am relatively new to C++, this is my first major project in C++. At this point, my breadth and depth of understanding of C++ represents an impediment to me but revisions provide the experience. Suggestions and comments are welcome.

###Contributors
  - Author: David York (Medmatix)

###Development Notes
#### A Todo List
1. Decide on the optimal approach to a mixed type list.
2. A complete set of getters and setter as will as appropriate to_string methods for each datatype constructed. Include formatted display methods for each structure.
3. Develop a list of functions member and non-member, to include as dataframe manipulator and analysis  functions.

#### Design directions

###Unit Testng Notes



###References and Acknowledgements
See related project, [UtilCSV](http://medmatix.github.io/UtilCSV)
and the consolidated library project incorportating all components,[libRDataFrame](http://medmatix.github.io/libRDataFrame)

###Contacts
Author web page, http://crunches-data.appspot.com
Email, medmatix@gmail.com

Copyright 2016 D.A.York
