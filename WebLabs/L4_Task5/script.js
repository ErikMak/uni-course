/* 
  Author: ErikMak
  Задание №5 лабораторной №4 
*/

// TEST DATA
const questions = [
	{answer: 3},
	{answer: 1},
	{answer: 2},
	{answer: 3}
]

function checkAnswer(checkbox) {
	const question_id = parseInt(checkbox.name[9]);
	const answer_id = parseInt(checkbox.value);

	const answer = questions[question_id].answer;

	if (answer == answer_id) {
		return true;
	} else {
		return false;
	}
}

function checkAnswers() {
	// Количество правильных ответов
	let counter = 0;

	let checkboxes = document.querySelectorAll('input[type="radio"]');
	checkboxes.forEach(function (checkbox) {
		if(checkbox.checked && checkAnswer(checkbox)) {
			counter++;
		}
	});

	saveResults(counter);
}

function saveResults(result) {
	if(localStorage.getItem('current_try') == null) {
		localStorage.setItem('current_try', result);
		localStorage.setItem('last_try', 0);
	} else {
		localStorage.last_try = localStorage.getItem('current_try');
		localStorage.current_try = result;
	}
}

function hideTest() {
	const check_btn = document.querySelector('.btn-check-answers');
	const again_btn = document.querySelector('.btn-again');

	check_btn.classList.add('is-hidden');
	for(let i = 0; i < questions.length; i++) {
		const question = document.querySelector('#question_'+i);
		question.classList.add('is-hidden');
	}
	again_btn.classList.remove('is-hidden');
}

function showTest() {
	const check_btn = document.querySelector('.btn-check-answers');
	const again_btn = document.querySelector('.btn-again');
	const resultHandle = document.querySelector('.results');

	check_btn.classList.remove('is-hidden');
	for(let i = 0; i < questions.length; i++) {
		const question = document.querySelector('#question_'+i);
		question.classList.remove('is-hidden');
	}
	again_btn.classList.add('is-hidden');
	resultHandle.classList.add('is-hidden');
}

function printResults() {
	const resultHandle = document.querySelector('.results');

	const last_try_field = resultHandle.querySelector('.last_try');
	const current_try_field = resultHandle.querySelector('.current_try');

	// Запись в карточку результатов
	const current_try = localStorage.getItem('current_try');
	const last_try = localStorage.getItem('last_try');

	current_try_field.innerHTML = current_try;
	last_try_field.innerHTML = last_try;

	resultHandle.classList.remove('is-hidden');
}

document.addEventListener('DOMContentLoaded', function() {
	console.log('Скрипт написан https://github.com/ErikMak');
	let check_btn = document.querySelector('.btn-check-answers');
	let again_btn = document.querySelector('.btn-again');

	check_btn.addEventListener('click', e => {
		e.preventDefault();

		hideTest();
		checkAnswers();
		printResults();
	});

	again_btn.addEventListener('click', e => {
		e.preventDefault();

		showTest();
	});
});