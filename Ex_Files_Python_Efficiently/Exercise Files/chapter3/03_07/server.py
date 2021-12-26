import flask, jinja2

app = flask.Flask(__name__)


template = jinja2.Template("""
    <html>
        <body>
            <img src = "{{imgdata}}"/>
        </body>
    </html>
""")

#@app.route('/sol')
#def getSol(sol):
    
@app.route('/')
def hello_world():
    return flask.Response('<html><body><h1> Hello! </h1></body></html>')

app.run(host='0.0.0.0')
