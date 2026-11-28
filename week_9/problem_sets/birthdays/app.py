import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session, url_for

MONTH = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
DAYS_PER_MONTH = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # Add the user's entry into the database
        name = request.form.get("name")
        try:
            month = int(request.form.get("month"))
            day = int(request.form.get("day"))
        except (ValueError, TypeError):
            month = 0
            day = 0
    

        has_name = True if name else False
        has_valid_date = 0 < month <= 12 and 0 < day <= DAYS_PER_MONTH[month - 1]

        if has_name and has_valid_date:
            db.execute("INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?)", name.strip(), month, day)
            return redirect('/')

        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", has_name=has_name, has_valid_date=has_valid_date, birthdays=birthdays, MONTH=MONTH)

    else:

        # Display the entries in the database on index.html
        birthdays = db.execute("SELECT * FROM birthdays")

        return render_template("index.html", has_name=True, has_valid_date=True, birthdays=birthdays, MONTH=MONTH)

@app.route("/remove", methods=["POST"])
def remove():
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM birthdays WHERE id = ?", id)
    return redirect('/')


