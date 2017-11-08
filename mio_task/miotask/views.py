from django.shortcuts import render, redirect
from miotask.forms import UserForm, ExtendForm, UserNumber, UserName
from django.contrib import messages
import random
from miotask.models import ExtendUser
from django.contrib.auth.models import User


def update_profile(request):
    if request.method == 'POST':
        user_form = UserForm(request.POST)
        extend_form = ExtendForm(request.POST)
        if user_form.is_valid() and extend_form.is_valid():
            user = user_form.save()
            user.extenduser.birthday_date = extend_form.cleaned_data.get('birthday_date')
            user.extenduser.random_number = random.randint(1,100)
            user_form.save()
            messages.success(request, 'Your profile was successfully updated!')
            user_form.save()
            return redirect('/miotask/showusers')
        else:
            messages.error(request, 'Please correct the error below.')
    else:
        user_form = UserForm()
        extend_form = ExtendForm()
    return render(request, 'profile.html', {
        'user_form': user_form,
        'extend_form': extend_form
    })

def show_users(request):
    users = User.objects.all()
    return render(request, 'users.html', {
        'users': users
    })


def get_user(request):
    if request.method == 'POST':
        user_form = UserNumber(request.POST)
        if user_form.is_valid():
            user_id = user_form.cleaned_data.get('user_number')
            user = User.objects.get(pk = user_id)
            exuser = ExtendUser.objects.get(user_id = user_id)
            return render(request, 'show_user.html', {
                'user': user,
                'exuser': exuser
            })
        else:
            messages.error(request, 'Please correct the error below.')
    else:
        user_form = UserNumber()
        
    return render(request, 'user.html', {'user_form': user_form})

def delete_user(request):
    if request.method == 'POST':
        user_form = UserName(request.POST)
        if user_form.is_valid():
            user_name = user_form.cleaned_data.get('user_name')
            user = User.objects.get(username = user_name)
            user.delete()
            return redirect('/miotask/showusers')
        else:
            messages.error(request, 'Please correct the error below.')
    else:
        user_form = UserName()
        
    return render(request, 'del_user.html', {'user_form': user_form})

