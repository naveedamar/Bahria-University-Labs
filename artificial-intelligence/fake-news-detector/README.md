# Fake News Detector

An AI-powered web application that classifies news articles as Real or Fake using Machine Learning.

## Disclaimer
This model is trained on US political news from 2015–2018. It may misclassify articles from other regions, languages, or time periods. It detects writing patterns — it does not fact-check.

## How It Works
Paste any news article or headline into the app. The model analyzes the text and returns a classification (Real or Fake) along with a confidence score.

## Tech Stack
- Python
- Streamlit
- Scikit-learn (TF-IDF + Logistic Regression)
- Pandas
- Joblib

## Dataset
WELFake Dataset — 72,134 labeled news articles from 4 sources (Kaggle, McIntire, Reuters, BuzzFeed).

Download: [WELFake Dataset on Kaggle](https://www.kaggle.com/datasets/vcclab/welfake-dataset)

Or run the following to download automatically:
```bash
python dataset.py
```
## Model Accuracy
93.9% on the test set.

## Setup

Install dependencies:
```bash
pip install streamlit scikit-learn pandas joblib python-dotenv
```

Train the model:
```bash
python train.py
```

Run the app:
```bash
streamlit run app.py
```
