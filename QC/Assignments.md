# <p style="text-align:center">Experiment 8</p> 

**Title:**  
Write Python code to “Implement Circuit Formation-1”

---

**Aim:**  
To implement quantum circuits that generate various quantum states and operations using Python. These circuits will include sequential circuits, Bell state, GHZ (Greenberger-Horne-Zeilinger) state, Quantum Fourier Transform (QFT) on 3 qubits, and Quantum Phase Estimation (QPE).

---

**Objective:**  
- To understand and simulate different quantum circuits in Python using NumPy.
- To explore the behavior of qubits through quantum gate applications.
- To simulate entangled states (Bell and GHZ states).
- To implement Quantum Fourier Transform (QFT) and Quantum Phase Estimation (QPE).

---

**Theory:**

1. **Quantum Circuits:**  
   Quantum circuits consist of qubits and quantum gates. A quantum gate alters the state of a qubit, and a quantum circuit involves applying multiple gates sequentially to qubits.

2. **Sequential Circuit:**  
   A sequential circuit applies quantum gates in a specific order to qubits, changing the quantum state step-by-step. These gates may include Hadamard, Pauli-X, and Controlled-NOT (CNOT).

3. **Bell State:**  
   The Bell state is an entangled state involving two qubits, representing maximal entanglement between them. The most common Bell state is $\frac{|00\rangle + |11\rangle}{\sqrt{2}}$, which means both qubits are in superposition and their states are correlated.

4. **GHZ (Greenberger-Horne-Zeilinger) State:**  
   GHZ states are entangled states of three or more qubits, where all qubits are either in $|000\rangle$ or $|111\rangle$ with equal probability. It generalizes the concept of the Bell state to more than two qubits.

5. **Quantum Fourier Transform (QFT):**  
   QFT is the quantum version of the classical Fourier transform. It transforms a quantum state into its Fourier components. QFT is widely used in many quantum algorithms, such as Shor’s algorithm for factoring integers.

6. **Quantum Phase Estimation (QPE):**  
   QPE is used to estimate the phase of an eigenvalue associated with a unitary operator. It is crucial in quantum algorithms, especially in factoring large numbers and solving linear systems.

---

**Mathematical Definitions:**

1. **Hadamard Gate (H):**
   $$
   H = \frac{1}{\sqrt{2}}\begin{pmatrix} 1 & 1 \\ 1 & -1 \end{pmatrix}
   $$
   The Hadamard gate creates superposition by mapping $|0\rangle$ to $\frac{|0\rangle + |1\rangle}{\sqrt{2}}$.

2. **Pauli-X Gate (X):**
   $$
   X = \begin{pmatrix} 0 & 1 \\ 1 & 0 \end{pmatrix}
   $$
   This is the quantum version of the classical NOT gate, which flips $|0\rangle$ to $|1\rangle$ and vice versa.

3. **Controlled-NOT Gate (CNOT):**
   $$
   CNOT = \begin{pmatrix} 1 & 0 & 0 & 0 \\ 0 & 1 & 0 & 0 \\ 0 & 0 & 0 & 1 \\ 0 & 0 & 1 & 0 \end{pmatrix}
   $$
   The CNOT gate flips the target qubit if the control qubit is in the state $|1\rangle$.

4. **Quantum Fourier Transform (QFT):**
   For a state vector $|\psi\rangle$ with $N$ qubits, QFT transforms the state vector using the Fourier transform:
   $$
   QFT |k\rangle = \frac{1}{\sqrt{N}} \sum_{j=0}^{N-1} e^{2\pi i k j / N} |j\rangle
   $$
   It maps the computational basis states to their Fourier basis states.

5. **Quantum Phase Estimation (QPE):**  
   For a unitary operator $U$ and a state $|\psi\rangle$, QPE estimates the phase $\theta$ in the equation:
   $$
   U|\psi\rangle = e^{2\pi i \theta}|\psi\rangle
   $$
   QPE is used to find this phase $\theta$.

---

**Code:**

Below is the Python code that implements all the circuits discussed:

```python
import numpy as np

# Define quantum gates
def hadamard_gate():
    return np.array([[1, 1], [1, -1]]) / np.sqrt(2)

def pauli_x_gate():
    return np.array([[0, 1], [1, 0]])

def cnot_gate():
    return np.array([[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 0, 1], [0, 0, 1, 0]])

def phase_gate(phase):
    return np.array([[1, 0], [0, np.exp(2j * np.pi * phase)]])

def controlled_z_gate():
    return np.array([[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, -1]])

# Create initial state |00> for 2 qubits, |000> for 3 qubits
def create_initial_state(n_qubits):
    return np.array([1] + [0] * (2**n_qubits - 1))

# Apply a quantum gate to the quantum state
def apply_gate(gate, state):
    return np.dot(gate, state)

# Print the quantum state in computational basis
def print_quantum_state(state, n_qubits):
    for i in range(2**n_qubits):
        print(f"|{i:0{n_qubits}b}>: {state[i]:.4f}")

# Sequential Circuit
def sequential_circuit():
    n_qubits = 2
    state = create_initial_state(n_qubits)
    print("Initial State:")
    print_quantum_state(state, n_qubits)

    # Apply Hadamard gate to the first qubit
    hadamard = np.kron(hadamard_gate(), np.eye(2))
    state = apply_gate(hadamard, state)
    print("\nAfter applying Hadamard gate on qubit 1:")
    print_quantum_state(state, n_qubits)

    # Apply CNOT gate
    cnot = cnot_gate()
    state = apply_gate(cnot, state)
    print("\nAfter applying CNOT gate:")
    print_quantum_state(state, n_qubits)

    # Apply Pauli-X gate to the second qubit
    pauli_x = np.kron(np.eye(2), pauli_x_gate())
    state = apply_gate(pauli_x, state)
    print("\nAfter applying Pauli-X gate on qubit 2:")
    print_quantum_state(state, n_qubits)

# Bell State
def bell_state():
    n_qubits = 2
    state = create_initial_state(n_qubits)
    print("Initial State:")
    print_quantum_state(state, n_qubits)

    # Apply Hadamard gate to the first qubit
    hadamard = np.kron(hadamard_gate(), np.eye(2))
    state = apply_gate(hadamard, state)
    print("\nAfter applying Hadamard gate on qubit 1:")
    print_quantum_state(state, n_qubits)

    # Apply CNOT gate
    cnot = cnot_gate()
    state = apply_gate(cnot, state)
    print("\nAfter applying CNOT gate (Bell State):")
    print_quantum_state(state, n_qubits)

# GHZ State
def ghz_state():
    n_qubits = 3
    state = create_initial_state(n_qubits)
    print("Initial State:")
    print_quantum_state(state, n_qubits)

    # Apply Hadamard gate to the first qubit
    state = apply_gate(hadamard_gate(), state)
    print("\nAfter applying Hadamard gate on qubit 1:")
    print_quantum_state(state, n_qubits)

    # Apply CNOT gate between qubit 1 and qubit 2
    cnot = cnot_gate()
    state = apply_gate(np.kron(cnot, np.eye(2)), state)
    print("\nAfter applying CNOT gate between qubit 1 and 2 (GHZ State):")
    print_quantum_state(state, n_qubits)

# QFT on 3 Qubits
def qft():
    n_qubits = 3
    state = create_initial_state(n_qubits)
    print("Initial State:")
    print_quantum_state(state, n_qubits)

    # Apply Hadamard gate to the first qubit
    state = apply_gate(hadamard_gate(), state)
    print("\nAfter applying Hadamard gate:")
    print_quantum_state(state, n_qubits)

    # Apply controlled phase gates
    for qubit in range(1, n_qubits):
        state = apply_gate(phase_gate(1/2**qubit), state)
    print("\nAfter applying controlled phase gates (QFT):")
    print_quant

um_state(state, n_qubits)

# Quantum Phase Estimation (QPE)
def qpe():
    n_qubits = 4
    state = create_initial_state(n_qubits)
    print("Initial State:")
    print_quantum_state(state, n_qubits)

    # Apply Hadamard gate to control qubits
    for i in range(n_qubits - 1):
        state = apply_gate(hadamard_gate(), state)
    print("\nAfter applying Hadamard gate:")
    print_quantum_state(state, n_qubits)

    # Apply controlled Z gates
    for i in range(n_qubits - 1):
        state = apply_gate(controlled_z_gate(), state)
    print("\nAfter applying controlled-Z gate (QPE):")
    print_quantum_state(state, n_qubits)

if __name__ == "__main__":
    print("Sequential Circuit:")
    sequential_circuit()
    
    print("\nBell State:")
    bell_state()
    
    print("\nGHZ State:")
    ghz_state()
    
    print("\nQFT on 3 Qubits:")
    qft()
    
    print("\nQuantum Phase Estimation:")
    qpe()
```

---

**Result:**



### **Conclusion:**

In this assignment, we successfully implemented various quantum circuits using Python, including the **Sequential Circuit**, **Bell State**, **GHZ State**, **Quantum Fourier Transform (QFT)**, and **Quantum Phase Estimation (QPE)**. Through the application of fundamental quantum gates such as Hadamard, Pauli-X, CNOT, and controlled-phase gates, we observed how qubits evolve and interact in quantum systems. This exercise provided a practical understanding of key quantum concepts, including **superposition**, **entanglement**, and **phase estimation**. By simulating these circuits, we gained insights into their behavior and importance in quantum computing, laying the groundwork for further exploration in quantum algorithms and advanced quantum applications.