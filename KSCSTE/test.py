"""# build the lightgbm model
import lightgbm as lgb
import joblib
gbm_pickle = joblib.load('C:\.others\Projects\KSCSTE\lgb (1).pkl')

newdata=gbm_pickle.predict([[90, 42, 43, 20.879744, 75, 5.5,220]])
newdata
"""
import pandas as pd
import numpy as np
import random

import matplotlib.pyplot as plt

cropdf = pd.read_csv("C:\.others\Projects\KSCSTE\Crop_recommendation.csv")
cropdf.head()
X = cropdf.drop('label', axis=1)
y = cropdf['label']
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.3,
                                                    shuffle = True, random_state = 0)

# build the lightgbm model
import lightgbm as lgb

model = lgb.LGBMClassifier()

model.fit(X_train, y_train)
model.feature_names = list(X_train.columns.values)
print(model.feature_names)
import joblib
joblib.dump(model, 'final_pc.pkl')
