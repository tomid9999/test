#import lightgbm as lgb
import joblib
gbm_pickle = joblib.load("""C:\.others\Projects\KSCSTE\hello.pkl""")

#['N', 'P', 'K', 'temperature', 'humidity', 'ph', 'rainfall']
newdata=gbm_pickle.predict([[0.80, 0.22, 0.89, 22.63, 92.33, 5.929,112.65]])
print(newdata[0])
