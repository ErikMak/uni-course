/* 
  Author: ErikMak
  Задание №3 лабораторной №3 
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
		const cardHandle = document.getElementById(checkbox.name);
		setSuccessFor(cardHandle);
	} else {
		const cardHandle = document.getElementById(checkbox.name);
		setErrorFor(cardHandle);
	}
}

function setSuccessFor(card) {
	card.classList.remove('success', 'error');
	card.classList.add('success');
}

function setErrorFor(card) {
	card.classList.remove('success', 'error');
	card.classList.add('error');
}

document.addEventListener('DOMContentLoaded', function() {
	console.log('Скрипт написан https://github.com/ErikMak');
	let checkboxes = document.querySelectorAll('input[type="radio"]');

	checkboxes.forEach(function (checkbox) {
		checkbox.addEventListener('change', function () {
			checkAnswer(this);
		});
	});
});