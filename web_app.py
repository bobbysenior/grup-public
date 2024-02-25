from flask import Flask, render_template, url_for
from waitress import serve

template_dir = "/home/blc/Projet/grup-web/static"

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
    #app.run(debug=False)
    serve(app, port=8080, host="0.0.0.0")
