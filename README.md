# Simple Machine Learning in Odin
A simple example of how to train your dragon, sorry, your Machine Leaning Model and use it on the Odin programming language.

## What this is?
1. It's a full example of how to run a ML Model on a Odin program.
2. It allows you to train your model in SciKit-lean in Python and export it to a ``` .h ``` of C++, with the MicroMLGen Library.
3. In a very easy way, you can modify the wrapper that I made in C++ that includes the ``` .h ``` created in the previous step. For example, selecting one or more classifiers or regressors to be used at the same time.
4. Than see my makefile and change the name to compile for your files to create a compilation unit object  ``` .o ``` file with CLang.
5. You can also, see the executable in C++ to test it directly in C++, before going to Odin, there is a executable in C++ in this example.
6. You can call the all the predictors from Odin. You just have to modify de Odin file and the wrapper a little.  


## Example
This is a simple example of the usage of the RandomForest classifier from Odin.

``` odin
    // For this input data. You should see '2' as the predicted class.
    iris_sample : [4]f32 = [4]f32{ 6.2, 2.8, 4.8, 1.8}

    fmt.printf("\nODIN: The predicted class for iris_sample : [4]f32 = [4]f32{6.2, 2.8, 4.8, 1.8}, should be '2'...\n");
 
    predicted_class_number : int = predict_classifier( int( Classifiers.Random_forest ), raw_data( iris_sample[:] ) )
        
    fmt.printf("ODIN: Result -> Predicted class : %d\n\n", predicted_class_number );
```

## Description
This uses the incredible MicroMLGen Library from Eloquent Arduino and it was made for embedded devices with low memory. But it works fine in also on a PC. I tested this on Linux.

1. Eloquent Arduino <br>
   [https://eloquentarduino.com/](https://eloquentarduino.com/)

2. MicroMLGen library for Python <br>
   A Python library to export scikit-learn models into C format with a single line of code <br>
   [https://eloquentarduino.com/micromlgen/](https://eloquentarduino.com/micromlgen/)

3. GitHub -  MicroMLGen <br>
   [https://github.com/eloquentarduino/micromlgen/tree/master](https://github.com/eloquentarduino/micromlgen/tree/master)


All the supported classifiers and regressors by MicroMLGen :

1. DecisionTree
  
2. RandomForest
  
3. XGBoost
  
4. GaussianNB
  
5. Support Vector Machines (SVC and OneClassSVM)
  
6. Relevant Vector Machines (from skbayes.rvm_ard_models package)
  
7. SEFR
  
8. PCA

## Important note
See all the article and all the documentation in the GitHub of MicroMLGen, the links are above.

## Installation

``` bash
############################################
# To create the a project for the directory.
$ mkdir odin_ml_inference

$ cd odin_ml_inference


###############################################
# To create the virtual environment called vend

$ python -m venv venv

$ source venv/bin/activate

$ pip install --upgrade pip

$ pip install sklearn

$ pip install scikit-learn


##################################
# To install and use MicrMLGen.

# MicroMLGen library for Python 
# https://eloquentarduino.com/micromlgen/

# GitHub - micromlgen
# https://github.com/eloquentarduino/micromlgen

# To install micromlgen.
pip install -U micromlgen
```

## Final notes

1. Don't forget to customize the wrapper for your needs, adding classifier and regressors, and uncommenting the type alias in the comments.
2. Make a copy of the Makefile and add the change the relevant file names.
3. The number od samples passed to the classifier, has to be correct, the same number that you used to train the classifier, because there is not any check inside MicroMLGen ``` .h ``` header file.
4. If you add more classifiers add them also to the enum in Odin, in the same corresponding order.
5. In Odin code to optimize for speed you can add to the odin compiler in the Makefile the ``` -speed ``` flag and the ``` - O3 ``` to the CLang compiler to compile the wrapper in C++.
6. The compilation of the wrapper, has to have the C++17 flag because it uses a feature in lambdas that is only present in C++17. 

## License
MIT Open Source license.

## Have fun
Best regards, <br>
Joao Carvalho

