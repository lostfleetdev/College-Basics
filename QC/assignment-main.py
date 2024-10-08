import numpy as np

# Define basic gates
def hadamard_gate(): return np.array([[1, 1], [1, -1]]) / np.sqrt(2)
def pauli_x_gate(): return np.array([[0, 1], [1, 0]])
def cnot_gate(): return np.array([[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 0, 1], [0, 0, 1, 0]])
def phase_gate(phase): return np.array([[1, 0], [0, np.exp(2 * np.pi * phase)]])

# Initialize and apply gate
def apply_gate(gate, state, qubits, n_qubits):
    full_gate = np.eye(2**n_qubits)
    if len(qubits) == 1:
        idx = qubits[0]
        full_gate = np.kron(np.eye(2**idx), np.kron(gate, np.eye(2**(n_qubits - idx - 1))))
    return np.dot(full_gate, state)

# Print quantum state
def print_state(state, n_qubits): 
    for i in range(2**n_qubits): print(f"|{i:0{n_qubits}b}>: {state[i]:.4f}")

# Quantum Circuits: Bell State, GHZ, QFT, QPE
def bell_state():
    state = np.array([1, 0, 0, 0])
    state = apply_gate(hadamard_gate(), state, [0], 2)
    state = apply_gate(cnot_gate(), state, [], 2)
    print_state(state, 2)

def ghz_state():
    state = np.array([1] + [0]*7)
    state = apply_gate(hadamard_gate(), state, [0], 3)
    state = apply_gate(cnot_gate(), state, [], 3)
    print_state(state, 3)

def qft():
    state = np.array([1] + [0]*7)
    state = apply_gate(hadamard_gate(), state, [0], 3)
    state = apply_gate(phase_gate(0.5), state, [1], 3)
    state = apply_gate(hadamard_gate(), state, [1], 3)
    print_state(state, 3)

def qpe():
    state = np.array([1] + [0]*15)
    for i in range(3):
        state = apply_gate(hadamard_gate(), state, [i], 4)
    state = apply_gate(phase_gate(0.5), state, [1], 4)
    print_state(state, 4)

if __name__ == "__main__":
    print("Bell State:"); bell_state()
    print("\nGHZ State:"); ghz_state()
    print("\nQFT:"); qft()
    print("\nQPE:"); qpe()
