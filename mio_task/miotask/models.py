from django.db import models
from django.contrib.auth.models import User
import random
from django.db.models.signals import post_save
from django.dispatch import receiver

class ExtendUser(models.Model):
    user = models.OneToOneField(User, on_delete = models.CASCADE)
    birthday_date = models.DateField(null=True)
    random_number = models.PositiveSmallIntegerField(default = 0)
    
@receiver(post_save, sender=User)
def create_extend_user(sender, instance, created, **kwargs):  
    if created:  
        ExtendUser.objects.create(user=instance)
    instance.extenduser.save()
