# MPAA Rating Prediction Dataset
### Temporal Feature Vectors for Age Rating Classification

This dataset provides temporal feature sequences extracted from feature-length films and video clips. It is designed to train and evaluate models for predicting **MPAA-style age ratings** (`G`, `PG`, `PG-13`, `R`) based on visual content analysis.

## 📊 Dataset Content

The dataset consists of binary feature files stored in the `/Data` directory, representing the output of EmotionLib's CNN backbones (`filter.dll` and `positiveness.dll`).

### File Types
- **`.efp` (Emotion Filter Predictions)**: 
  - Channels: `[Safe, Explicit, Gore]`
  - Used to detect brief moments of violence or adult content.
- **`.epp` (Emotion Positiveness Predictions)**: 
  - Channels: `[Negative, Positive]`
  - Used to analyze the overall emotional tone and atmosphere.

## 🧠 Classification Challenges & Label Noise
This dataset includes diverse content types, ranging from short clips to full-length movies (max duration: ~6h 26m). It highlights specific challenges in automated rating:

*   **Contextual Violence:** *'Way of the Dragon'* (1972) is technically `PG` but contains martial arts violence that modern models may score closer to `R`.
*   **Thematic Intensity:** *'Titanic'* (`PG-13`) contains intense sequences that border on `R` in pure visual analysis.
*   **Genre Ambiguity:** *'Kickboxer'* (1989) represents a boundary case between `PG-13` and `R`.

## 🛡️ Anonymization Protocol
Due to the inclusion of sensitive samples utilized for negative constraints (NSFW/Gore), all entries are **anonymized** using a code system (e.g., `PG-13-404`, `GORE-1`). This ensures the dataset remains a pure research artifact for signal processing and pattern recognition.

## 🔗 Integration
Designed for the **MPAA Rating System** module within `samp.dll`.
> **Training Guide:** [EmotionLib MPAA Training Notebook](../../notebooks/emotionlib-mpaa-train.ipynb)
