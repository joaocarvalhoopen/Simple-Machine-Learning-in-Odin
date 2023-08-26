# See:
# Eloquent Arduino article - Random Forest Classifier
# MicroMLGen library for Python 
# https://eloquentarduino.com/micromlgen/
#

# This script trains a Random Forest Classifier on the Iris dataset.
# It then generates the C code for the classifier and saves it to a file.

from micromlgen import port
from sklearn.ensemble import RandomForestClassifier
from sklearn.datasets import load_iris


if __name__ == '__main__':
    X, y = load_iris(return_X_y=True)
    clf = RandomForestClassifier(n_estimators=10).fit(X, y)
    c_code = port(clf)

    with open('ex_01_random_forest_classifier.h', 'w') as file:
        file.write(c_code)