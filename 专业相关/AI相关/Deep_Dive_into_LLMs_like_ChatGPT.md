# 来源
[视频链接](https://www.youtube.com/watch?v=7xTGNNLPyMI&list=PLAqhIrjkxbuW9U8-vZ_s_cjKPT_FqRStI&index=3)
# 笔记
## Pretraining 
### Step 1: download and preprocess the internet
[FineWeb（预训练数据集](https://huggingface.co/spaces/HuggingFaceFW/blogpost-fineweb-v1)

<img width="1277" height="514" alt="image" src="https://github.com/user-attachments/assets/8888c4b7-f0c1-468c-a374-e96f98c92ecc" />
1. URL filtering: 主要是注意 blocklist
    (https://dsi.ut-capitole.fr/blacklists), 读取数据要拦截这些不应出现的网站

### Step 2: tokenization
<img width="449" height="307" alt="image" src="https://github.com/user-attachments/assets/206bf340-483a-4f28-809d-1350b4384a55" />


[tiktokenizer](https://tiktokenizer.vercel.app/),可以看到系统怎么拆分的token
### Step 3: neural network training 
<img width="765" height="324" alt="image" src="https://github.com/user-attachments/assets/a4d484a7-a037-409a-bf24-5b24ec2a4e01" />


#### neural network internals
<img width="960" height="469" alt="image" src="https://github.com/user-attachments/assets/d0ec51d9-a5e6-4118-ac0c-feec2c2e2f39" />


### Step 4: inference
<img width="1119" height="633" alt="image" src="https://github.com/user-attachments/assets/ed225658-7d0b-4711-9924-8ee2653b8bc8" />


## Demo: reproducing OpenAI's GPT-2
<img width="528" height="271" alt="image" src="https://github.com/user-attachments/assets/0b14a890-43ec-4f9c-ac95-5ae23c2076f4" />

[github链接](https://github.com/karpathy/llm.c/discussions/677)
[deepwiki](https://deepwiki.com/karpathy/llm.c/5-data-processing#binary-data-format)
# Append
