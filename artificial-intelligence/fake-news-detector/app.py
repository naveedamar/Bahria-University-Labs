# loading the saved model and vectorizer, building a streamlit ui to predict if a news article is fake or real

import streamlit as st
import joblib

model = joblib.load("model.pkl")
vectorizer = joblib.load("vectorizer.pkl")

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

        if prediction == 0:
            st.error(f"Fake News — Confidence: {confidence[0]*100:.2f}%")
        else:
            st.success(f"Real News — Confidence: {confidence[1]*100:.2f}%")