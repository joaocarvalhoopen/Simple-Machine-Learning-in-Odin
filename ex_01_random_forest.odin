package simple_ML_predictor

import "core:fmt"
import "core:strings"

// External C object import.
when ODIN_OS == .Linux   do foreign import foo { "ex_01_random_forest_wrapper.o", "stdc++" }   // "libc++" }

foreign foo {
    predict_classifier :: proc "c" ( predictor_number : int, in_sample_arr : [^]f32 /* , in_sample_len : int */ ) -> int ---
}

Classifiers :: enum {
    Random_forest = 0,
    bla_bla_erroneous_classifier = 1,
}

main :: proc() {
    // This is a simple example of the usage of the RandomForest classifier from Odin.

    // For this input data. You should see '2' as the predicted class.
    iris_sample : [4]f32 = [4]f32{ 6.2, 2.8, 4.8, 1.8}

    fmt.printf("\nODIN: The predicted class for iris_sample : [4]f32 = [4]f32{6.2, 2.8, 4.8, 1.8}, should be '2'...\n");
 
    // iris_sample_ptr : [^]f32 = raw_data( iris_sample[:] ) 
    predicted_class_number : int = predict_classifier( int( Classifiers.Random_forest ), raw_data( iris_sample[:] ) )
    
    // This will give you an assert because it is a erroneous classifier.
    // So only create the Classifiers enum with the correct number and position of the classifier.
    // predicted_class_number_2 : int = predict_classifier( int( Classifiers.bla_bla_erroneous_classifier ), raw_data( iris_sample[:] ) )
    
    fmt.printf("ODIN: Result -> Predicted class : %d\n\n", predicted_class_number );
}

