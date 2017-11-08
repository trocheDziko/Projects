from django import forms
from miotask.models import User, ExtendUser

class UserForm(forms.ModelForm):
    class Meta:
        model = User
        fields = ['username']

class ExtendForm(forms.ModelForm):
    class Meta:
        model = ExtendUser
        fields = ['birthday_date']

class UserNumber(forms.Form):
    user_number = forms.DecimalField(label='User id: ')

class UserName(forms.Form):
    user_name = forms.CharField(label='Username: ')

