# RFID Livestock Tracking System with AI-Driven Decision Support

This project integrates RFID-based animal identification with cloud services and machine learning models for health assessment, behavior anomaly detection, and breeding recommendations. It combines ESP32/ESP8266 firmware, a Node.js backend, and Python-based AI modules to provide intelligent livestock management.

---

## Core Features

### IoT System
- ESP32/ESP8266 firmware for RC522 RFID tag reading
- WiFi connectivity for real-time UID sync
- REST API integration with Node backend
- Modular firmware for field use by farmers
- Supports quick identification of goats via RFID tags

### AI System
- Supervised ML model for health risk prediction  
- Unsupervised anomaly detection model using scan behavior  
- Graph-based breeding recommendation engine  
- Model artifacts saved as `.pkl` for backend inference  
- Reusable Python pipelines for dataset preprocessing and feature engineering  
- Extensible design for future on-device inference (TFLite Micro)

---

## Project Structure

```
rfid_cattle_tracker/
│
├── ai/
│   ├── breeding/
│   │   ├── datasets/
│   │   │   └── sample_livestock_data.csv
│   │   ├── notebooks/
│   │   │   └── breeding_recommendation.ipynb
│   │   └── models/
│   │       └── breeding_graph.pkl
│   │
│   └── health_behavior/
│       ├── datasets/
│       │   ├── sample_livestock_data.csv
│       │   └── sample_scan_activity.csv
│       ├── notebooks/
│       │   ├── health_prediction.ipynb
│       │   └── anomaly_detection.ipynb
│       └── models/
│           ├── health_model.pkl
│           ├── anomaly_detector.pkl
│           └── anomaly_scaler.pkl
│
├── firmware/
│   ├── esp32_rfid.ino
│   └── esp8266_rfid.ino
│
├── server/
│   ├── server.js
│   ├── package.json
│   └── controllers/
│
├── docs/
├── requirements.txt
├── .gitignore
└── README.md
```

---

## AI Modules

### Health Risk Prediction (Supervised)
- Model: RandomForestClassifier
- Input features: age, weight, milk yield, temperature, previous issues, days since last breeding, sex
- Output: probability of requiring medical attention
- Notebook: `health_prediction.ipynb`
- Artifact: `health_model.pkl`

### Behavior Anomaly Detection (Unsupervised)
- Model: IsolationForest
- Features: total_scans, mean_interval_min, variance_interval, activity_score
- Output: anomaly_flag (normal/anomalous), anomaly_score
- Notebook: `anomaly_detection.ipynb`
- Artifacts: `anomaly_detector.pkl`, `anomaly_scaler.pkl`

### Breeding Recommendation Engine (Graph-Based)
- Builds a pedigree graph from parent relationships
- Computes relationship distance, inbreeding risk, compatibility score
- Suggests top candidate goats for safe breeding
- Notebook: `breeding_recommendation.ipynb`
- Artifact: `breeding_graph.pkl`

---

## IoT Components

### Hardware
- ESP32 or ESP8266 MCU
- RC522 RFID Reader
- 13.56 MHz passive RFID tags

### Firmware Capabilities
- UID extraction via SPI
- WiFi client for server communication
- JSON-based HTTP requests
- Serial logging for field debugging

### Backend (Node.js)
- Receives scans from IoT firmware
- Fetches and syncs goat profiles
- Can integrate with Python microservices for ML inference
- Stores activity logs for behavioral analysis

---

## Installation

### Python Environment
```
pip install -r requirements.txt
```

### Node Backend
```
cd server
npm install
npm start
```

### Jupyter Notebooks
```
jupyter lab
```

---

## requirements.txt Reference

```
pandas
numpy
scikit-learn
matplotlib
seaborn
networkx
fastapi
uvicorn
jupyter
```

---

## Intended Workflow

1. RFID device scans goat tag  
2. UID sent to backend via WiFi  
3. Backend retrieves animal profile  
4. AI modules provide:  
   - health risk prediction  
   - anomaly detection based on scan logs  
   - breeding recommendations  
5. Frontend/App displays enriched information to the farmer

---

## Future Work
- Deploy AI inference using FastAPI microservice  
- Incorporate GPS/UWB for spatial behavior patterns  
- Add time-series models for long-term health forecasting  
- Integrate TensorFlow Lite Micro for on-device inference on ESP32

