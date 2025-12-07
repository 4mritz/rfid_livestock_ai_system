import pickle
import pandas as pd

detector = pickle.load(open("models/anomaly_detector.pkl", "rb"))
scaler = pickle.load(open("models/anomaly_scaler.pkl", "rb"))

def detect(payload: dict):
    df = pd.DataFrame([payload])
    X_scaled = scaler.transform(df)
    flag = detector.predict(X_scaled)[0]
    score = detector.decision_function(X_scaled)[0]
    return {"anomaly_flag": int(flag), "anomaly_score": float(score)}

if __name__ == "__main__":
    example = {
        "total_scans": 3,
        "mean_interval_min": 90,
        "variance_interval": 350,
        "activity_score": 0.22
    }
    print(detect(example))
