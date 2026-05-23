# loading saved model and vectorizer, building streamlit ui to predict if news is fake or real

import streamlit as st
import joblib
import os

BASE_DIR = os.path.dirname(os.path.abspath(__file__))

model = joblib.load(os.path.join(BASE_DIR, "model.pkl"))
vectorizer = joblib.load(os.path.join(BASE_DIR, "vectorizer.pkl"))

st.title("Fake News Detector")
st.write("Paste a news article or headline below and the model will classify it as Real or Fake.")

user_input = st.text_area("Enter news text here:", height=200)

if st.button("Analyze"):
    if user_input.strip() == "":
        st.warning("Please enter some text first.")
    else:
        input_tfidf = vectorizer.transform([user_input])
        prediction = model.predict(input_tfidf)[0]
        confidence = model.predict_proba(input_tfidf)[0]

        if prediction == 1:
            st.error(f"Fake News — Confidence: {confidence[1]*100:.2f}%")
        else:
            st.success(f"Real News — Confidence: {confidence[0]*100:.2f}%")

st.markdown("---")

st.caption(
    "⚠️ **Disclaimer:** This model is trained on US political news from 2015–2018 (WELFake Dataset). "
    "It may misclassify articles from other regions, languages, or time periods. "
    "The model detects writing patterns — it does not fact-check. Use results as a reference only."
)

st.markdown(
    "<div style='text-align: center;'>"
    "<a href='https://github.com/naveedamar/Bahria-University-Labs/tree/main/artificial-intelligence/fake-news-detector' target='_blank'>"
    "<button style='background-color: #24292e; color: white; padding: 8px 20px; border: none; border-radius: 6px; cursor: pointer; font-size: 14px;'>"
    "⭐ View on GitHub</button></a></div>",
    unsafe_allow_html=True
)