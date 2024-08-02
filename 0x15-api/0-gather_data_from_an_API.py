#!/usr/bin/python3
""" Python script that, using this REST API, for a given employee ID,
returns information about his/her TODO list progress."""

import json
from urllib.request import urlopen
import requests
from sys import argv


if __name__ == "__main__":
    emp_id = argv[1]
    user_url = f"https://jsonplaceholder.typicode.com/users/{emp_id}"
    todos_url = "https://jsonplaceholder.typicode.com/todos"

    with urlopen(user_url) as res:
        user_data = res.read()
        user_dic = json.loads(user_data.decode("utf-8"))

    params = {"userID": emp_id}
    todos = requests.get(todos_url, params).json()

    completed = [t.get("title") for t in todos if t.get("completed") is True]
    print("Employee {} is done with tasks({}/{}):".format(
        user_dic.get("name"), len(completed), len(todos)))
    [print("\t {}".format(c)) for c in completed]
