from flask import Flask, render_template, url_for, request, jsonify
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


@app.route("/control", methods=['POST', 'GET'])
def control():
    # Check if the request contains JSON data
    if request.is_json:
        data = request.get_json()  # Get JSON data from the request
        # Assuming JSON data contains a 'name' field
        name = data.get('name')
        # Process the data (here we'll just echo it back)
        response_data = {'message': f'Hello, {name}! Your POST request was successful.'}
        return jsonify(response_data), 200  # Return a JSON response with a 200 status code
    else:
        return jsonify({'error': 'Request must contain JSON data.'}), 400  # Return an error if request doesn't contain JSON 
    return "Aled"

if __name__ == "__main__":
    #app.run(debug=False)
    serve(app, port=8080, host="0.0.0.0")
