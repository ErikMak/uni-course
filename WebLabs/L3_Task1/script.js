
let elem = document.getElementById("confirm-pass");
elem.addEventListener("focusout", validateForm);

let elem2 = document.getElementById("pass");
elem2.addEventListener("focusout", validateForm);

function validateForm() {
	let pass = document.forms["reg-form"]["pass"].value;
	let rep_pass = document.forms["reg-form"]["confirm-pass"].value;

	let form_group = document.getElementsByClassName("form-group")[5];

	form_group.classList.remove("success");

	if (rep_pass === pass) {
		form_group.classList.add("success");
	}
}