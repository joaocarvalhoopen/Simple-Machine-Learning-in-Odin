
#include <stdint.h>
#include <stdio.h>
#include "ex_01_random_forest_classifier.h"

// A wrapper is needed to use the C++ code in C.
// to export the C++ code to C, we need to use the extern "C" keyword.

// This is a simple example of the usage of the RandomForest classifier.
int main() {
    // For this input data. You should see '2' as the predicted class.
    float iris_sample[4] = {6.2, 2.8, 4.8, 1.8};

    Eloquent::ML::Port::RandomForest clf;
    printf("\nThe predicted class for iris_sample[4] = {6.2, 2.8, 4.8, 1.8}, should be '2'...\n");
    int predicted_class = clf.predict( iris_sample );
    printf("Result -> Predicted class : %d\n\n", predicted_class );

    return 0;
}
