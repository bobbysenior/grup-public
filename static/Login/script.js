document.addEventListener('DOMContentLoaded', function () {
    const form = document.querySelector('form');
  
    form.addEventListener('submit', function (event) {
      event.preventDefault();
      
      const usernameInput = document.querySelector('input[type="text"]');
      const passwordInput = document.querySelector('input[type="password"]');
      
      const username = usernameInput.value.trim();
      const password = passwordInput.value.trim();
  
      if (username === '' || password === '') {
        alert('Please enter both username and password.');
        return;
      }
      // Perform login logic here (e.g., send data to server)
      // For demonstration purposes, let's just log the credentials
      console.log('Username:', username);
      console.log('Password:', password);

      let loginSuccessful = false;
  
      //Check if the login is good
      if (username === "admin" && password ==="crampte"){
        loginSuccessful = true;
      }


      if (loginSuccessful) {
        // Redirect the user to another page
        window.location.href = '../Dashboard';
      } else {
        alert('Incorrect username or password.');
      }
    });
  });
  