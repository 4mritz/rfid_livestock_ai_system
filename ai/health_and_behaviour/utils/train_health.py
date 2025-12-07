import pickle
import pandas as pd

model = pickle.load(open("models/health_model.pkl", "rb"))

def predict(payload: dict):
    df = pd.DataFrame([payload])
    proba = model.predict_proba(df)[0][1]
    pred = int(proba > 0.5)
    return {"prediction": pred, "probability": float(proba)}

if __name__ == "__main__":
    example = {
        "age": 3,
        "sex": "F",
        "weight_kg": 38,
        "milk_yield_l": 1.4,
        "temperature_c": 39.4,
        "previous_issues": 1,
        "days_since_last_breeding": 40
    }
    print(predict(example))
