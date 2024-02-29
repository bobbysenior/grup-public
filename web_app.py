from flask import Flask, render_template, url_for, request
from waitress import serve

template_dir = "/home/bobby/Projet/grup-public/static"

app = Flask(__name__, template_folder=template_dir)

@app.route("/")
def home():
    return render_template("Home/home.html")

@app.route("/Login", methods=['POST', 'GET'])
def index():
    return render_template("Login/index.html")

@app.route("/Dashboard")
def dashboard():
    water_level = request.args.get('water_level') #From 0 to 100
    if water_level == None:
        water_level = 0
    return render_template("Dashboard/dashboard.html", water_level=water_level)

if __name__ == "__main__":
    #app.run(debug=False)
    serve(app, port=8080, host="0.0.0.0")
