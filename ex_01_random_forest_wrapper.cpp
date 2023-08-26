

#include <stdint.h>
#include <stdio.h>
#include <vector>
// To have a vector of vectors of different types.
#include <variant>


// This is a assert with a custom message, that prints the, current function, file and line.
# include <cassert>
#define CUSTOM_ASSERT(cond, msg) \
    do { \
        if (!(cond)) { \
            fprintf(stderr, "Assertion failed: (%s), function %s, file %s, line %d. " \
                    "Message: %s\n", #cond, __func__, __FILE__, __LINE__, msg); \
            assert(cond); \
        } \
    } while(0)


// Put here the header file of your generated classifier from your Model made in SciKit-Learn in Python.
#include "ex_01_random_forest_classifier.h"



// A wrapper is needed to use the C++ code in C.
// to export the C++ code to C, we need to use the extern "C" keyword.


// The different type of objects that we want to store in the vector ( Variant ).

using Random_forest_t = Eloquent::ML::Port::RandomForest;
// using Decision_tree_t = Eloquent::ML::Port::DecisionTree;

// ....
// ....
// ....

// TODO (for the user):
// Add the classifiers type for ones that you need for your specific case.

// using GaussianNB_t    = Eloquent::ML::Port::GaussianNB;
// using PCA_t           = Eloquent::ML::Port::PCA;
// using Principal_FFT_t = Eloquent::ML::Port::PrincipalFFT;

/* RVM is equal type to RVC. */
// using RVC_t           = Eloquent::ML::Port::RVC;
// using SEFR_t          = Eloquent::ML::Port::SEFR;

// using SVC_t           = Eloquent::ML::Port::SVC;
// using One_class_SVM_t = Eloquent::ML::Port::OneClassSVM;

/* XGBoost classifier. */
// using XGB_t           = Eloquent::ML::Port::XGB;

// using Logistic_regression_t     = Eloquent::ML::Port::LogisticRegression;
// using Linear_regression_t       = Eloquent::ML::Port::LinearRegression;
// using Decision_tree_regressor_t = Eloquent::ML::Port::DecisionTreeRegressor;
// using Random_forest_regressor_t = Eloquent::ML::Port::RandomForestRegressor;1


// A helper visitor structure for std::visit
struct Object_visitor_t {
    
    /* Random Forest type. */
    int operator( ) ( Random_forest_t & random_forest, float* in_sample_arr /* , int in_sample_len */ ) const {
        printf( "Random_forest_t will be call predict() .\n" );
        int res_predicted_class_number = random_forest.predict( in_sample_arr );
        printf( "Random_forest_t predict() was called.\n" );
        return res_predicted_class_number;
    }

    /* Decision Tree type. */
    // int operator( ) ( Decision_tree_t & decision_tree, float* in_sample_arr /* , int in_sample_len */ ) const {
    //     printf( "Decision_tree_t will be call predict() .\n" );
    //     int res_predicted_class_number = decision_tree.predict( in_sample_arr );
    //     printf( "Decision_tree_t predict() was called.\n" );
    //     return res_predicted_class_number;
    // }


    // ....
    // ....
    // ....


    // TODO (for the user):
    // Add a similar operator for each type of classifier that you want to use in your specific case.

    // GaussianNB_t    = Eloquent::ML::Port::GaussianNB;
    // PCA_t           = Eloquent::ML::Port::PCA;
    // Principal_FFT_t = Eloquent::ML::Port::PrincipalFFT;

    /* RVM is equal type to RVC. */
    // RVC_t           = Eloquent::ML::Port::RVC;
    // SEFR_t          = Eloquent::ML::Port::SEFR;

    // SVC_t           = Eloquent::ML::Port::SVC;
    // One_class_SVM_t = Eloquent::ML::Port::OneClassSVM;

    /* XGBoost classifier. */
    // XGB_t           = Eloquent::ML::Port::XGB;

    // Logistic_regression_t     = Eloquent::ML::Port::LogisticRegression;
    // Linear_regression_t       = Eloquent::ML::Port::LinearRegression;
    // Decision_tree_regressor_t = Eloquent::ML::Port::DecisionTreeRegressor;
    // Random_forest_regressor_t = Eloquent::ML::Port::RandomForestRegressor;1

};


// The different type of objects that we want to store in the vector ( Variant ).
using ObjectVariant = std::variant< Random_forest_t /* , Decision_tree_t, type_name_of_classifier_A, type_name_of_classifier_B  */  >;

// Fill the vector with the different type of objects predictor that your want to
// store in the vector ( Variant ).
std::vector<ObjectVariant> objects = { Random_forest_t(), /* , Decision_tree_t(), type_name_of_classifier_A(), type_name_of_classifier_B() */ };

// IMPORTANT: The order of the objects in the vector must be the same as the order
//            that you will specify in the function predict_classifier().
//            And in the classifier enumerator inside the Odin code that calls this
//            function.

Object_visitor_t visitor;

extern "C" {

    int predict_classifier(int predictor_number, float* in_sample_arr /* , int in_sample_len */ ) {
        CUSTOM_ASSERT( ( predictor_number >= 0 && predictor_number < objects.size() ), "The predictor number is out of range." );

        size_t mySize = 5;  // Replace with appropriate logic to compute array size
        Object_visitor_t visitor;

        // Call the predict function of the corresponding classifier.
        int res_predicted_data_class_number =
                std::visit([&](auto&& arg) -> int {
                    return visitor(arg, in_sample_arr /* , in_sample_len */ );
                }, objects[predictor_number]);
        
        return res_predicted_data_class_number;
    }

}

