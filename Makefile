
all: random_forest random_forest_main


clean: clean_random_forest


# -----------------------------------------------------------------------------
# Random Forest Classifier.
# -----------------------------------------------------------------------------

random_forest: ex_01_random_forest_train.py ex_01_random_forest_wrapper.cpp 
	python3 ex_01_random_forest_train.py
	clang -c ex_01_random_forest_wrapper.cpp -o ex_01_random_forest_wrapper.o -std=c++17 
	odin build . -out:ex_01_random_forest_main_odin.exe	-extra-linker-flags:"-lstdc++"
	
#	odin build . ex_01_random_forest.odin ex_01_random_forest_wrapper.o -out:ex_01_random_forest_main_odin.exe

random_forest_main: ex_01_random_forest_train.py ex_01_random_forest_main.cpp
	python ex_01_random_forest_train.py
	clang ex_01_random_forest_main.cpp -o ex_01_random_forest_main_c.exe -std=c++17

random_forest_run_c: random_forest_main ex_01_random_forest_main_c.exe 
	./ex_01_random_forest_main_c.exe

random_forest_run_odin: random_forest   
	./ex_01_random_forest_main_odin.exe


clean_random_forest:
	rm ex_01_random_forest_main_odin.exe ex_01_random_forest_main_c.exe ex_01_random_forest_wrapper.o ex_01_random_forest_classifier.h

# -----------------------------------------------------------------------------

