from django.http import HttpResponse

# Create your views here.

def index(request):
	return HttpResponse("Hello, world. Welcome to our tourism website")

def equity(votes, weights):
	"""
	:param votes: list of votes by the current team members e.g. [8, 9, 7.5, 0, ..]. Max is 10
	:param weights: list of weights, so team member i's final vote will be worth votes[i] * weights[i]. Max weight is 10

	:return: NA
	"""

	eqty = 0
	for i in range(len(weights)):
		eqty += weights[i] * votes[i]
	return eqty
