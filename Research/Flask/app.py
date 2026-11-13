from flask import Flask, render_template, request, redirect, url_for

app = Flask(__name__)

# Home page
@app.route('/')
def home():
    return render_template('index.html')

# About page
@app.route('/about')
def about():
    return '''
           <link rel="stylesheet" href="{{ url_for('static', filename='styles.css') }}">
           This is the About page.
           '''

# Contact page with form
@app.route('/contact', methods=['GET', 'POST'])
def contact():
    if request.method == 'POST':
        name = request.form.get('name')
        email = request.form.get('email')
        message = request.form.get('message')
        print(f"Received message from {name} ({email}): {message}")
        return redirect(url_for('home'))
    return '''
        <form method="post">
            Name: <input type="text" name="name"><br>
            Email: <input type="email" name="email"><br>
            Message: <textarea name="message"></textarea><br>
            <input type="submit" value="Submit">
        </form>
    '''

if __name__ == '__main__':
    app.run(debug=True)
