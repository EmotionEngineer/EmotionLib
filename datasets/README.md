# EmotionLib Datasets

This folder contains local copies of the datasets used to reproduce training of EmotionLib classification heads.

## Contents

- `unsafe-filter.zip`  
  Dataset for training the safety filter components (NSFW/Gore / SAMP-related training data).

- `mpaa-ratings.zip`  
  Dataset for training the MPAA-style rating classifier (`G`, `PG`, `PG-13`, `R`).

## Notes

- The archives are provided as `.zip` to keep repository structure stable across platforms.
- If you also use the Kaggle mirrors mentioned in the main repository README, treat this folder as the canonical offline copy for reproducible builds.

## Quick start

Unpack both archives into this folder:

```bash
cd datasets
unzip unsafe-filter.zip
unzip mpaa-ratings.zip
```

Then follow the step-by-step instructions in `../notebooks/`.
