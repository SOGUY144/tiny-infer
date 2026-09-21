# 🧠 Tiny-Infer (Nano-LLM in C++)

> **Project Mission**: Build a lightweight, pure C++ LLM inference engine from scratch (inspired by `llama.cpp` and `llama2.c`), with **zero external machine learning libraries** (no PyTorch, no TensorFlow, no CUDA required).

---

## 👤 Context & Learning Approach

- **Learner / Author**: Fahat Trongnasuk (`SOGUY144`)
- **Teaching Style**: **Step-by-step, 1-on-1 hand-in-hand mentoring (จับมือสอนเขียนตั้งแต่ศูนย์)**.
- **Rules of Engagement**:
  1. Do NOT dump giant walls of code.
  2. Explain every single concept, pointer, struct, and variable clearly before writing it.
  3. Allow the learner to ask questions at any time.
  4. Write clean, idiomatic modern C++ (compiled with `g++` via MinGW-w64 on Windows).

---

## 💻 Hardware & Environment

- **OS**: Windows 11
- **CPU**: 12th Gen Intel Core i5-12500H (12 Cores / 16 Threads, AVX2 enabled)
- **RAM**: 16 GB DDR4/DDR5
- **Compiler**: `g++` (MinGW-w64 POSIX UCRT) & `cmake` (already installed and verified in PATH)
- **Target Model**: TinyStories 15M / GPT-2 small (~15–60 MB weights, <100MB RAM usage)

---

## 🗺️ Step-by-Step Learning Roadmap

### 📍 Level 1: Memory & Tensor Foundations (The Basics)
- [x] **1.1 The C++ Memory Model for AI**: How numbers live in RAM (`float`, pointers, dynamic allocation vs stack).
- [x] **1.2 The 1D Flattened Array**: Why 2D/3D matrices in AI are stored as continuous 1D buffers (`index = row * cols + col`).
- [x] **1.3 Creating our first `Tensor` Struct**: Writing a simple, beautiful struct to manage tensor dimensions and data pointers.

### 📍 Level 2: The Core Math Engines (The Muscle)
- [x] **2.1 Matrix Multiplication (`MatMul`)**: The single most important operation in AI (Dot product of rows and columns).
- [ ] **2.2 Activation Functions**: Writing `Softmax`, `RMSNorm` (Root Mean Square Normalization), and `SiLU/SwiGLU`.
- [ ] **2.3 Verification Test**: Writing a small test program to verify that our math outputs match standard math.

### 📍 Level 3: The Transformer Architecture (The Brain)
- [ ] **3.1 Token Embeddings**: How a token ID (e.g. word "cat" = 42) turns into a vector of numbers.
- [ ] **3.2 Self-Attention Mechanism**: Query ($Q$), Key ($K$), Value ($V$), and Scaled Dot-Product Attention.
- [ ] **3.3 Multi-Head Attention (MHA)**: Splitting heads to focus on different contexts.
- [ ] **3.4 Feed-Forward Network (FFN)**: Expanding and contracting hidden dimensions.
- [ ] **3.5 Residual Connections**: Adding input back to output ($x + f(x)$) to preserve gradient and signals.

### 📍 Level 4: Model Weights & Tokenizer (Loading Real Data)
- [ ] **4.1 Binary Weight File Parser**: Opening `.bin` / `.gguf` files with `std::ifstream` and mapping bytes directly into our structs.
- [ ] **4.2 The BPE Tokenizer**: Reading vocabulary tokens and encoding text into integer IDs, and decoding IDs back into words.

### 📍 Level 5: The Inference Generation Loop (It Speaks!)
- [ ] **5.1 Next-Token Prediction**: Forward pass through the Transformer.
- [ ] **5.2 Sampling Strategies**: Greedy (Argmax) vs Temperature & Top-$p$ sampling.
- [ ] **5.3 Real-Time Streaming Output**: Printing tokens one by one to the console like ChatGPT/llama.cpp.

### 📍 Level 6: Optimization & Speedup (The Hardcore Part)
- [ ] **6.1 Multi-threading**: Using `std::thread` to split Matrix Multiplication across your 16 CPU threads.
- [ ] **6.2 SIMD Vectorization**: Unleashing `AVX2` intrinsics to compute 8 float multiplications in a single CPU cycle.

---

## 🚀 How to Start in a New Chat Session

When opening this workspace in Antigravity, simply tell the AI:
> *"สวัสดี! อ่านไฟล์ ROADMAP.md ในโฟลเดอร์นี้แล้ว มาเริ่มสอน Level 1.1 กันเลย!"*
