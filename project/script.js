let steps = [];
let currentStep = 0;
let finalResult = 0;

document.getElementById('runBtn').addEventListener('click', runVisualization);
document.getElementById('nextBtn').addEventListener('click', showNext);
document.getElementById('prevBtn').addEventListener('click', showPrev);

function runVisualization() {
  const arrInput = document.getElementById('arrayInput').value.trim();
  if (!arrInput) {
    alert("⚠ Please enter numbers separated by commas!");
    return;
  }
  const arr = arrInput.split(',').map(Number);
  steps = kadaneSteps(arr);
  currentStep = 0;
  finalResult = Math.max(...steps.map(s => s.maxSoFar));
  showStep();
  showFinalResult();
}

function kadaneSteps(arr) {
  let steps = [];
  let maxSoFar = arr[0];
  let currentMax = arr[0];
  steps.push({ i: 0, currentMax, maxSoFar });

  for (let i = 1; i < arr.length; i++) {
    currentMax = Math.max(arr[i], currentMax + arr[i]);
    maxSoFar = Math.max(maxSoFar, currentMax);
    steps.push({ i, currentMax, maxSoFar });
  }
  return steps;
}

function showStep() {
  if (steps.length === 0) return;
  const step = steps[currentStep];

  const visualizer = document.getElementById('visualizer');
  visualizer.innerHTML = "";

  steps.forEach((s, index) => {
    const box = document.createElement("div");
    box.className = "step-box";
    if (index === currentStep) box.classList.add("active");
    box.textContent = s.currentMax;
    visualizer.appendChild(box);
  });

  document.getElementById('output').textContent =
    `Step ${currentStep + 1}/${steps.length} → CurrentMax = ${step.currentMax}, MaxSoFar = ${step.maxSoFar}`;
}

function showNext() {
  if (currentStep < steps.length - 1) {
    currentStep++;
    showStep();
  }
}

function showPrev() {
  if (currentStep > 0) {
    currentStep--;
    showStep();
  }
}

function showFinalResult() {
  const resultCard = document.getElementById('resultCard');
  const resultValue = document.getElementById('resultValue');
  resultCard.style.display = "block";
  resultValue.textContent = ` The Maximum Subarray Sum is: ${finalResult}`;
}
