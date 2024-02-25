from flask import Flask, render_template, url_for

template_dir = "/home/bobby/Projet/grup-web/static"

app = Flask(__name__, template_folder=template_dir)

@app.route("/")
def home():
    return render_template("Home/home.html")

@app.route("/Login", methods=['POST', 'GET'])
def index():
    return render_template("Login/index.html")

@app.route("/Dashboard")
def dashboard():
    return render_template("Dashboard/dashboard.html")

if __name__ == "__main__":
    app.run(debug=True)